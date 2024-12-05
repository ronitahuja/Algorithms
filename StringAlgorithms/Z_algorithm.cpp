/*
Time complexity: O(m+n)
Space complexity: O(n)
where n is the length of the string.
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define int long long
#define float double
#define null nullptr
#define N static_cast<int>(1e5+10)
#define pi (3.141592653589)
#define mod 1000000007
#define mini INT_MIN
#define maxi INT_MAX
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

vector<string> Split(string &s, string key)
{
   int start = 0, pos = 0;
   vector<string> res;
   while ((pos = s.find(key, start)) != string::npos){
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
vector<int> calculate_z_arr(string &s) {
   int n = s.size();
   vector<int> z(n, 0);
   int l = 0, r = 0;
   for (int i = 1; i < n; i++) {
      if (i <= r) {
         z[i] = min(r - i + 1, z[i - l]);
      }
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
         z[i]++;
      }
      if (i + z[i] - 1 > r) {
         l = i;
         r = i + z[i] - 1;
      }
   }
   return z;
}
int32_t main() {
   string s;cin>>s;
   string p;cin>>p;
   string t = p + "$" + s;
   vector<int> z=calculate_z_arr(t);
   for(int i=p.size()+1;i<t.size();i++){
      if(z[i]==p.size()){
         cout<<i-p.size()-1<<" ";
      }
   }
   return 0;
}