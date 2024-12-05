/*
Time Complexity: O((V+E)logV)
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
void dijkstra(int source, vector<vector<pair<int, int>>> &adjl)
{
    vector<int> dist(adjl.size(), INT_MAX);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    while (!pq.empty())
    {
        int curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();
        for (auto i : adjl[curr])
        {
            if (curr_d + i.second < dist[i.first])
            {
                dist[i.first] = curr_d + i.second;
                pq.push({dist[i.first], i.first});
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
    dijkstra(source, adjl);
    return 0;
}