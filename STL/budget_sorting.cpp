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
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   sort(arr,arr+n);
   for(int i=1;i<n;i++){
    arr[i]+=arr[i-1];
   }
   while(q--){
    int b;
    cin>>b;
    auto it = upper_bound(arr,arr+n,b)-arr;
    cout<<it<<endl;
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