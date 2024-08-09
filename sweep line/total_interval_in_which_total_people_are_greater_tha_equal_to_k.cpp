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
   vector<pair<int,int>> edgelist;
   for(int i=0;i<n;i++){
    int l,r;
    cin>>l>>r;
    edgelist.push_back({l,+1});
    edgelist.push_back({r,-1});
   }
   sort(edgelist.begin(),edgelist.end());
   int cnt=0;
   int ans=0;
   for(int i=0;i<edgelist.size();i++){
    cnt+=edgelist[i].S;
    if(i+1<edgelist.size() && cnt>=k){
        ans+=edgelist[i+1].F-edgelist[i].F;
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