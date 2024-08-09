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
   int arr[n];
   for(int i=0;i<n;i++){
        cin>>arr[i];
   }

   int ans = 0;

   for(int i=0;i<60;i++){
    int cnt1 = 0;
    for(int j=0;j<n;j++){
        if((arr[j]&(1LL<<i))){
            cnt1++;
        }
    }
    ans+= (1LL<<i)*cnt1*(cnt1-1)/2;
   }

   cout<<ans<<endl;
    
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