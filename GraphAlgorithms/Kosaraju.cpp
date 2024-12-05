/*
Time Complexity: O(V+E)
Space Complexity: O(V+E)
used to find strongly connected components in a graph
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
void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;
    for (auto &it : graph[node])
    {
        if (!visited[it])
        {
            dfs(it, graph, visited, st);
        }
    }
    st.push(node);
}
void dfs2(vector<vector<int>> &transpose, int node, vector<bool> &visited, vector<int> &scc)
{
    visited[node] = true;
    scc.push_back(node);
    for (auto &it : transpose[node])
    {
        if (!visited[it])
        {
            dfs2(transpose, it, visited,scc);
        }
    }
}
void kosaraju(vector<vector<int>> &graph, int vertices)
{
    stack<int> st;
    vector<bool> visited(vertices, false);
    // topological sort
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            dfs(i, graph, visited, st);
        }
    }
    // reverse the edges
    vector<vector<int>> transpose(vertices);
    for (int i = 0; i < vertices; i++)
    {
        for (auto &it : graph[i])
        {
            transpose[it].push_back(i);
        }
    }
    // dfs on transpose graph according to the order of stack
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> ans;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!visited[node])
        {
            vector<int> scc;
            dfs2(transpose, node, visited, scc);
            ans.push_back(scc);
        }
    }
    for (const auto &scc : ans)
    {
        for (int node : scc)
        {
            cout << node << " ";
        }
        cout << endl;
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
    kosaraju(graph, vertices);
    return 0;
}