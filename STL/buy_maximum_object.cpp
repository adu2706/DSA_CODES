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
   int n,m;
   cin>>n>>m;
   vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        
    }
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
        
    }

    auto it = upper_bound(arr.begin(),arr.end(),m);
    int ans = it - arr.begin();
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