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
   int n,L;
   cin>>n>>L;
   vector<pair<int,int>> events;
   for(int i=0;i<n;i++){
    int l,r;
    cin>>l>>r;
    events.push_back({l,r});
   }

   map<int,int> mp;
   for(auto v:events){
    //if some point have same starting point then we can store the ending point which are very far
    mp[v.F] = max(mp[v.F],v.S);
   }

   int start = 0;
   int end = 0;
   int ans = 0;
   for(auto v:mp){
    if(v.F==start){
        end = max(end,v.S);
        start = end;
        ans++;
    }else if(v.F>start){
        ans++;
        start = end;  
    }
    end = max(end,v.S);
   }

   if(start<L){
    ans++;
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