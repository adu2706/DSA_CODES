#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int n;
int check(int mid){
    int k = (n*n +1)/2; //mid point
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cnt+=min(mid/i,n);
        if(cnt>=k){
            return 1;
        }
    }
    return 0;
}

void solve(){
   cin>>n;
   int lo = 1;
   int hi = n*n;
   int ans = 0;
   while(lo<=hi){
    int mid = (lo+hi)/2;
    if(check(mid)){
        ans = mid;
        hi = mid-1;
    }else{
        lo = mid+1;
    }
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