/**/
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
int32_t main()
{
    fast_io;
    int edges, vertices;
    cin >> vertices >> edges;
    vector<vector<int>> graph(vertices);
    vector<int> indegree(vertices, 0);
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for (int i = 0; i < vertices; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int processedNodes = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        processedNodes++;
        for (auto &it : graph[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    if (processedNodes != vertices)
    {
        cout << "Cycle exists" << endl;
    }
    return 0;
}