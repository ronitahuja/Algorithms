/*
Time Complexity: O(V+E)
Space Complexity: O(V+E)
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

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[node] = true;
    for (auto &it : graph[node])
    {
        if (!visited[it])
        {
            dfs(it, graph, visited);
        }
    }
}

// Check if all vertices with non-zero degree are in the same strongly connected component
bool isStronglyConnected(vector<vector<int>> &graph, int vertices)
{
    vector<bool> visited(vertices, false);
    int nonZeroDegree = -1;
    for (int i = 0; i < vertices; i++)
    {
        if (graph[i].size() > 0)
        {
            nonZeroDegree = i;
            break;
        }
    }
    if (nonZeroDegree == -1)
        return true;

    dfs(nonZeroDegree, graph, visited);
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i] && graph[i].size() > 0)
            return false;
    }

    // Now check the reverse graph (for strong connectivity)
    vector<vector<int>> reverseGraph(vertices);
    for (int i = 0; i < vertices; i++)
    {
        for (int j : graph[i])
        {
            reverseGraph[j].push_back(i);
        }
    }

    fill(visited.begin(), visited.end(), false);
    dfs(nonZeroDegree, reverseGraph, visited);

    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i] && graph[i].size() > 0)
            return false;
    }
    return true;
}

int EulerPath(vector<vector<int>> &graph, int vertices)
{
    if (!isStronglyConnected(graph, vertices)) // only one strongly connected component should be present
        return false;

    vector<int> inDegree(vertices, 0), outDegree(vertices, 0);
    for (int i = 0; i < vertices; i++)
    {
        for (int v : graph[i])
        {
            outDegree[i]++;
            inDegree[v]++;
        }
    }

    int start = 0, end = 0;
    for (int i = 0; i < vertices; i++)
    {
        if (outDegree[i] - inDegree[i] == 1)
            start++;
        else if (inDegree[i] - outDegree[i] == 1)
            end++;
        else if (outDegree[i] != inDegree[i])
            return 0; // no Euler path or circuit
    }

    if (start == 1 && end == 1)
        return 1; // Euler path
    if (start == 0 && end == 0)
        return 2; // Euler circuit
    return 0;     // no Euler path or circuit
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
    cout << EulerPath(graph, vertices);
    return 0;
}
