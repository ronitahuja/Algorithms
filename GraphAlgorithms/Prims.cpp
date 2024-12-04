/**/
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
void prims(vector<pair<int, pair<int, int>>> &edgeslist, int nodes)
{
   vector<vector<pair<int,int>>> adjl(nodes);
   for(auto &i:edgeslist){
      adjl[i.second.first].push_back({i.second.second,i.first});
      adjl[i.second.second].push_back({i.second.first,i.first});
   }
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
   vector<bool> visited(nodes,false);
   int sum=0;
   pq.push({0,0});
   while(!pq.empty()){
      pair<int,int> p=pq.top();
      pq.pop();
      int w=p.first;
      int node=p.second;
      if(visited[node]) continue;
      visited[node]=true;
      sum+=w;
      for(auto &i:adjl[node]){
         if(!visited[i.first]){
            pq.push({i.second,i.first});
         }
      }
   }
   cout<<sum<<endl;
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
   prims(edgeslist, nodes);
   return 0;
}