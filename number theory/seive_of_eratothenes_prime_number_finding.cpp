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
    int n = 1e7+10;
   int is_prime[n];
   for(int i=2;i<n;i++){
    is_prime[i] = 1;
   }

   for(int i=2;i<n;i++){
    if(is_prime[i]){
        for(long long j=1LL*i*i;j<n;j+=i){
            is_prime[j]=0;
        }
    }
   }

    //tc = O(nlog(log(n)));
    
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