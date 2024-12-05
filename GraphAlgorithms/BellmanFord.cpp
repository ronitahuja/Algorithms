/*
Time Complexity: O(V*E)
Space Complexity: O(V)
*/
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
void bellmanford(int source, vector<vector<pair<int, int>>> &adjl,int vertices)
{
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;
    for(int count=1;count<=vertices-1;count++){
        for(auto &edge:adjl){
            int u=edge.first;
            int v=edge.second;
            int w=edge.third;
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }
    for (int i = 0; i < dist.size(); i++)
        cout << dist[i] << " ";
}
int32_t main()
{
    fast_io;
    int edges, nodes;
    cin >> nodes >> edges;
    vector<vector<pair<int, int>>> adjl(nodes);
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjl[u].push_back({v, w});
        adjl[v].push_back({u, w});
    }
    int source;
    cin >> source;
    bellmanford(source, adjl,int nodes);
    return 0;
}