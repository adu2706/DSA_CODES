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
   int n,X;
   cin>>n>>X;
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   int prefix[n+1]={0};
   for(int i=1;i<=n;i++){
    prefix[i] = prefix[i-1]+arr[i-1];
   }

   map<int,int> mp;
   int ans = 0;
   mp[0]++;
   for(int i=1;i<=n;i++){
    ans+=mp[prefix[i]-X];
    mp[prefix[i]]++;
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