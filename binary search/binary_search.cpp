#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int n,x;
int arr[1000100];

bool check(int mid){
    if(arr[mid]>=x){
        return 1;
    }else{
        return 0;
    }
}

void solve(){
   cin>>n>>x;
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }

   int lo = 0;
   int hi = n;
   int ans = n;

   while(lo<=hi){
     int mid = (lo+hi)/2;
     if(check(mid)==1){
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