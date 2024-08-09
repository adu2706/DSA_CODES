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
   int is_prime[n+1];
   is_prime[1]=0;
   for(int i=2;i<=n;i++){
    is_prime[i]=1;
   }
   for(int i=2;i<=n;i++){
    if(is_prime[i]){
        for(int j=1LL*i*i;j<=n;j+=i){
            is_prime[j] = 0;
        }
    }
   }

   int phi[n+1];
   for(int i=1;i<=n;i++){
    phi[i] = i;
   }

   for(int i=2;i<=n;i++){
    if(is_prime[i]){
        for(int j=i;j<=n;j+=i){
            phi[j] = phi[j]-(phi[j]/i);
        }
    }
   }


    for(int i=1;i<=n;i++){
        cout<<phi[i]<<" ";
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