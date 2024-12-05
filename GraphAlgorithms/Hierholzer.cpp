/*hierholzer using dfs*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define int long long
#define float double
#define null nullptr
#define N static_cast<int>(1e5 + 10)
#define pi (3.141592653589)
#define mod 1000000007
#define mini INT_MIN
#define maxi INT_MAX
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

vector<string> Split(string &s, string key)
{
   int start = 0, pos = 0;
   vector<string> res;
   while ((pos = s.find(key, start)) != string::npos)
   {
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
void dfs(int node, vector<vector<int>> &graph, vector<int> &path)
{
   while (!graph[node].empty())
   {
      int v = graph[node].back();
      graph[node].pop_back();
      dfs(v, graph, path);
   }
   path.push_back(node);
}
void hierholzer(vector<vector<int>> &graph, int vertices)
{
   vector<int> in(vertices), out(vertices);
   for (int i = 0; i < vertices; i++)
   {
      for (auto &it : graph[i])
      {
         in[it]++;
         out[i]++;
      }
   }
   int start = 0;
   // start is outdegree - indegree = 1
   // end is indegree - outdegree = 1
   int startCount = 0, endCount = 0;
   for (int i = 0; i < vertices; i++)
   {
      if (out[i] - in[i] == 1)
      {
         start = i;
         startCount++;
         break;
      }
      else if (out[i] != in[i])
      {
         cout << "Euler path/circuit is not possible\n";
         return;
      }
      else if (in[i] - out[i] == 1)
      {
         endCount++;
      }
   }
   if (startCount > 1 || endCount > 1)
   {
      cout << "Euler path/circuit is not possible\n";
      return;
   }
   vector<int> path;
   dfs(start, graph, path);
   reverse(path.begin(), path.end());
   for (int &i : path)
   {
      cout << i << " ";
   }
}
int32_t main()
{
   fast_io;
   int edges, vertices;
   cin >> vertices >> edges;
   vector<vector<int>> graph(vertices);
   for (int i = 0; i < edges; i++)
   {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
   }
   hierholzer(graph, vertices);
   return 0;
}