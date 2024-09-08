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
   int n,q;
   cin>>n>>q;
   vector<int> arr(n+1,0);
    vector<int> drr(n+1,0);
    vector<int> dx(n+1,0);

    while(q--){
        int a,d,l,r;
        cin>>a>>d>>l>>r;
        arr[l] += a;
        drr[l] += (d%mod*l%mod)%mod;
        dx[l] += d;
        if(r+1<=n){
            arr[r+1] = (arr[r+1]%mod - a%mod + mod)%mod;
            drr[r+1] = (drr[r+1]%mod - (d%mod*l%mod)%mod + mod)%mod; 
            dx[r+1] = (dx[r+1]%mod - d%mod + mod)%mod;
        }
    }

    for(int i=1;i<=n;i++){
        (arr[i]+=arr[i-1]%mod)%=mod;
        (drr[i]+=drr[i-1]%mod)%=mod;
        (dx[i] += dx[i-1]%mod)%=mod;
    }

    for(int i=1;i<=n;i++){
        drr[i] = ((dx[i]%mod*i%mod)%mod - drr[i]%mod + mod)%mod;
    }

    vector<int> ans(n+1,0);
    for(int i=1;i<=n;i++){
        ans[i] = (arr[i]%mod+drr[i]%mod + mod)%mod;
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]%mod<<" ";
    }
    cout<<endl;
    
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