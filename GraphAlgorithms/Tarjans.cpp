/*
Tarjan's Algorithm is used to find all Strongly Connected Components in a Directed Graph.
A Strongly Connected Component (SCC) of a directed graph is a maximal strongly connected subgraph.
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
void Tarjans(int nodes, vector<vector<int>> &adjl)
{
    vector<int> disc(nodes, -1), low(nodes, -1);
    vector<bool> onStack(nodes, false);
    stack<int> st;
    int time = 0;
    function<void(int)> dfs = [&](int u)
    {
        disc[u] = low[u] = time++;
        st.push(u);
        onStack[u] = true;
        for (int v : adjl[u])
        {
            if (disc[v] == -1)
            {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if (onStack[v])
            {
                low[u] = min(low[u], disc[v]);
            }
        }
        if (disc[u] == low[u])
        {
            while (st.top() != u)
            {
                cout << st.top() << " ";
                onStack[st.top()] = false;
                st.pop();
            }
            cout << st.top() << "\n";
            onStack[st.top()] = false;
            st.pop();
        }
    };
    for (int i = 0; i < nodes; i++)
    {
        if (disc[i] == -1)
            dfs(i);
    }
}
int32_t main()
{
    fast_io;
    int edges, nodes;
    cin >> nodes >> edges;
    vector<vector<int>> adjl(nodes);
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjl[u].push_back(v);//for zero based indexing
    }
    Tarjans(nodes, adjl);

    return 0;
}