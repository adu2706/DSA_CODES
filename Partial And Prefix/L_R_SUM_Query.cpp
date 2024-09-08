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
   int n , q;
   cin>>n>>q;
   int prefix[n];
   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    if(i==0){
        prefix[i] = x%mod;
    }else{
        prefix[i] =(x%mod +prefix[i-1]%mod + mod)%mod;
    }
   }

    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        int ans = l==0?prefix[r]%mod:((prefix[r]%mod)-(prefix[l-1]%mod)+mod)%mod;
        cout<<ans<<endl;
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}