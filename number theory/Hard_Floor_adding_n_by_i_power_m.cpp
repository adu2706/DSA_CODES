#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int binpowi(int a, int b, int mod){
	a%=mod;
    int res=1;
    while(b>0){
    	if(b&1){ 
        res = (res%mod*a%mod)%mod;
    	}
    	a = (a%mod*a%mod)%mod;
    	b>>=1;
    }
    return (res)%mod;
}


int inverse(int a, int mod){
    return ((binpowi(a, mod-2, mod)%mod)+mod)%mod;
}


void solve(){
   int n,m;
   cin>>n>>m;
   int ans = 0;
   for(int i=1,la;i<=n;i=la+1){
     la = n/(n/i);
     ans = (ans+(binpowi((n/i),m,mod)%mod)*(la-i+1)%mod)%mod;
   }

   cout<<ans%mod<<endl;
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