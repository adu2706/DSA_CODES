#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


void solve(){
   int n;
   cin>>n;
   map<int,string> mp;
   for(int i=0;i<n;i++){
        string s;
        int x;
        cin>>s>>x;
        mp[x] = s;
   }

   for(auto x:mp){
    cout<<x.second<<" "<<x.first<<endl;
   }
    
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