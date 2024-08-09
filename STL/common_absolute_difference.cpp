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
 int n,k;
 cin>>n>>k;
 int arr[n];
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }

 sort(arr,arr+n);
    int ans  = 0;
 for(int i=0;i<n;i++){
    auto it = upper_bound(arr,arr+n,arr[i]+k);
    auto it1 = lower_bound(arr,arr+n,arr[i]+k);

    it--;
    if(*it==arr[i]+k  && *it1==arr[i]+k){
        ans += it-it1+1;
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