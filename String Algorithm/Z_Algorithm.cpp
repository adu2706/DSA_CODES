#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


//at particular index i how much prefix at i match with prefix at index at 0 index and both substring are proper substring

vector<int> Z_funtion(string &s){
    int n = s.length();
    vector<int> z(n);
    z[0] = 0;
    for(int i=1,l=0,r=0;i<n;i++){
        if(l<=r){
            z[i] = min(r-i+1,z[i-l]);
        }
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
            ++z[i];
        }
        if(i+z[i]-1 > r){
            l = i;
            r = i+z[i]-1;
        }
    }
    return z;
}

void solve(){
   
    
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}