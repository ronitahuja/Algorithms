/*
Time complexity: O(n)
Space complexity: O(n)
where n is the length of the string.
used to find the longest palindromic substring in a string.
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
vector<int> manacher(string &s)
{
   string t = "#" + string(1, s[0]);
   for (int i = 1; i < s.size(); ++i)
      t += "#" + string(1, s[i]);
   t += "#";
   int n = t.size();
   vector<int> p(n, 0);
   int l = 0, r = 0;
   for (int i = 0; i < n; i++)
   {
      p[i] = (i < r) ? min(r - i, p[l + (r - i)]) : 0;
      while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 &&
             t[i + p[i] + 1] == t[i - p[i] - 1])
         p[i]++;
      if (i + p[i] > r)
         l = i - p[i], r = i + p[i];
   }
   return p;
}
string longestPalindrome(string s)
{
   vector<int> p = manacher(s);
   int resLen = 0, center_idx = 0;
   for (int i = 0; i < p.size(); i++)
   {
      if (p[i] > resLen)
      {
         resLen = p[i];
         center_idx = i;
      }
   }
   int resIdx = (center_idx - resLen) / 2;
   return s.substr(resIdx, resLen);
}
int32_t main()
{
   fast_io;
   string s;
   cin >> s;
   cout << longestPalindrome(s);
   return 0;
}