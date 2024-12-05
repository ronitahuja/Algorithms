/*
Time Complexity: O(ElogE) or O(ElogV)
Space Complexity: O(V+E)
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define int long long
#define float double
#define null nullptr
#define N static_cast<int>(1e5+10)
#define pi (3.141592653589)
#define mod 1000000007
#define mini INT_MIN
#define maxi INT_MAX
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

vector<string> Split(string &s, string key)
{
   int start = 0, pos = 0;
   vector<string> res;
   while ((pos = s.find(key, start)) != string::npos){
      res.push_back(s.substr(start, pos - start));
      start = pos + key.size();
   }
   res.push_back(s.substr(start));
   return res;
}

string Trim(string &s)
{
   int start = 0, end = s.size() - 1;
   while (start < s.size() && s[start] == ' ')
      start++;
   while (end >= 0 && s[end] == ' ')
      end--;
   return s.substr(start, end - start + 1);
}
class DSU{
   public:
   vector<int> parent, rank;
   DSU(int n){
      parent.resize(n);
      rank.resize(n);
      for(int i=0; i<n; i++){
         parent[i] = i;
         rank[i] = 0;
      }
   }
   int findp(int x){
      if(parent[x] == x)
         return x;
      return parent[x] = findp(parent[x]);
   }
   void uni(int x, int y){
      x = findp(x);
      y = findp(y);
      if(x != y){
         if(rank[x] < rank[y])
            swap(x, y);
         parent[y] = x;
         if(rank[x] == rank[y])
            rank[x]++;
      }
   }
};
void kruskals(vector<pair<int, pair<int, int>>> &edgeslist, int nodes){
   sort(edgeslist.begin(), edgeslist.end());
   DSU dsu(nodes);
   int cost = 0;
   vector<pair<int, int>> mst;
   for(auto i: edgeslist){
      int w = i.first;
      int u = i.second.first;
      int v = i.second.second;
      if(dsu.findp(u) != dsu.findp(v)){
         cost += w;
         mst.push_back({u, v});
         dsu.uni(u, v);
      }
   }
   cout << cost << endl;
   for(auto i: mst){
      cout << i.first << " " << i.second << endl;
   }
}
int32_t main() {
   fast_io;
   int edges, nodes;
   cin >> nodes >> edges;
   vector<pair<int, pair<int, int>>> edgeslist;
   for (int i = 0; i < edges; i++)
   {
      int u, v, w;
      cin >> u >> v >> w;
      edgeslist.push_back({w, {u, v}});
   }
   kruskals(edgeslist, nodes);
   return 0;
}