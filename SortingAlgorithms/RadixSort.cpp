/**/
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
void countingsort(vector<int> &arr) {
    int n = arr.size();
    int max = *max_element(arr.begin(), arr.end());
    vector<int> count(max + 1, 0);
    for(int i:arr)count[i]++;
    int index=0;
    for(int i=0;i<=max;i++){
        while(count[i]>0){
            arr[index++]=i;
            count[i]--;
        }
    }
}
void radixsort(vector<int> &arr) {
    int n = arr.size();
    int max = *max_element(arr.begin(), arr.end());
    for(int exp=1;max/exp>0;exp*=10){
        vector<int> count(10,0);
        vector<int> output(n);
        for(int i=0;i<n;i++) count[(arr[i]/exp)%10]++;
        for(int i=1;i<10;i++) count[i]+=count[i-1];
        for(int i=n-1;i>=0;i--){
            output[count[(arr[i]/exp)%10]-1]=arr[i];
            count[(arr[i]/exp)%10]--;
        }
        for(int i=0;i<n;i++) arr[i]=output[i];
    }
}
int32_t main() {
   fast_io;
   int n;cin>>n;
   vector<int> arr(n);
   for(int i=0;i<n;i++) cin>>arr[i];
   radixsort(arr);
   for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}