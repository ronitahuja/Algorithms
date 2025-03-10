/*
Time Complexity: O(V^3)
Space Complexity: O(V^2)
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
void floydwarshall(vector<vector<int>> &adjl, int vertices)
{
    for (int k = 0; k < vertices; k++)
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (adjl[i][k] != INT_MAX && adjl[k][j] != INT_MAX && adjl[i][k] + adjl[k][j] < adjl[i][j])
                {
                    adjl[i][j] = adjl[i][k] + adjl[k][j];
                }
            }
        }
    }
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << adjl[i][j] << " ";
        }
        cout << endl;
    }
}
int32_t main()
{
    fast_io;
    int edges, nodes;
    cin >> nodes >> edges;
    vector<vector<int>> adjl(nodes, vector<int>(nodes, INT_MAX));
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjl[u][v] = w;
    }
    floydwarshall(adjl, nodes);
    return 0;
}