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
   for(int i=1;i<=n;i++){
    cin>>arr[i];
   }

   vector<int> pref1(n+1,0);
   for(int i=1;i<=n;i++){
    pref1[i]=((pref1[i-1]+mod)%mod+(arr[i]%mod)%mod+mod)%mod;
   }
   vector<int> pref2(n+1,0);
   for(int i=1;i<=n;i++){
    pref2[i]=((pref2[i-1]+mod)%mod+((arr[i]+mod)%mod*i%mod)%mod)%mod;
   }

   while(q--){
    int l,r;
    cin>>l>>r;
    int sumxi = (((pref1[r]+mod)%mod)-((pref1[l-1]+mod)%mod)+mod)%mod;
    int sumixi = (((pref2[r]+mod)%mod)-((pref2[l-1]+mod)%mod)+mod)%mod;
    int sumlxi = ((l%mod)*(((pref1[r]+mod)%mod)-((pref1[l-1]+mod)%mod)+mod)%mod)%mod;
    int ans = (((sumxi+mod)%mod + (sumixi+mod)%mod +mod)%mod - ((sumlxi+mod)%mod) + mod)%mod;
    cout<<ans%mod<<endl;
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