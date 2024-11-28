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
vector<int> lps(string &p)
{
    int n = p.size();
    vector<int> lps(n, 0);
    int len = 0;
    for(int i=0;i<n;){
        if(p[i]==p[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len==0){
                lps[i]=0;
                i++;
            }
            else{
                len=lps[len-1];
            }
        }
    }
    return lps;
}
void kmp(string &s, string &p)
{
    vector<int> lps_arr = lps(p);
    int n = s.size(), m = p.size();
    int i = 0, j = 0;
    while (i < n)
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << "Pattern found at index " << i - j << endl;
            j = lps_arr[j - 1];
        }
        else if (i < n && s[i] != p[j])
        {
            if (j == 0)
                i++;
            else
                j = lps_arr[j - 1];
        }
    }
}
int32_t main()
{
    string s = "abcabcabcabc";
    string p = "abcabc";
    kmp(s, p);
    return 0;
}