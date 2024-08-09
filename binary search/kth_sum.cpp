#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int n,m,k;
vector<int> arr,brr;

bool check(int mid){
    int cnt = 0;
    for(int i=0;i<n;i++){
        auto it = upper_bound(brr.begin(),brr.end(),mid-arr[i])-brr.begin();
        cnt += it;
        if(cnt>=k){
            return 1;
        }
    }
    return 0;
}

void solve(){
   cin>>n>>m>>k;
   arr.resize(n);
   brr.resize(m);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   for(int j=0;j<m;j++){
    cin>>brr[j];
   }

    if(n>m){
        swap(n,m);
        swap(arr,brr);
    }

    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());

   int lo = 0;
   int hi = 1e18;
   int ans = 1e18;
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
    cin>>t;
    while(t--){
        solve();
    }
}