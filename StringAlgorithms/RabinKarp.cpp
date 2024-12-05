/*
Time complexity: O(m+n) sometimes O(mn)
Space complexity: O(1)
where m is the length of the pattern and n is the length of the text.
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
#define prime 101

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
int getHash(const string &p){
    int hash=0;
    for(int i=0;i<p.size();i++){
        hash+=p[i]*pow(prime,i);
    }
    return hash;
}
int updateHash(string &s,int oldHash,int size,char oldChar,char newChar){
    int newhash=(oldHash-oldChar)/prime;
    newhash+=newChar*pow(prime,size-1);
    return newhash;
}
int32_t main()
{
    string s;
    cin>>s;
    string p;
    cin>>p;
    int n=s.size();
    int m=p.size();
    int hash=getHash(p);
    int shash=getHash(s.substr((int)0,(int)(m)));
    if(hash==shash){
        cout<<"Pattern found at index 0\n";
    }
    for(int i=1;i<=n-m;i++){
        shash=updateHash(s,shash,m,s[i-1],s[i+m-1]);
        if(shash==hash){
            cout<<"Pattern found at index "<<i<<"\n";
        }
    }
    return 0;
}