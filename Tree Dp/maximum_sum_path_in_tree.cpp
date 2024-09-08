#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


vector<vector<int>> g;
vector<int> val;
vector<int> dp1,dp2; //dp1 for single path starting through a node in straight down direction
//dp2 for path passing through node in two direction 
int ans = 0;
int n;

void dfs(int node, int par){
    dp1[node] = val[node];
    int maxi1 = 0;
    int maxi2 = 0;
    for(auto v:g[node]){
        if(v!=par){
            dfs(v,node);

            //consider path starting from node
            dp1[node] = max(dp1[node],dp1[node]+(dp1[v]));

            //consider path passing through node
            if(dp1[v]>maxi1){
                maxi2 = maxi1;
                maxi1 = dp1[v];
            }else if(dp1[v]>maxi2){
                maxi2 = dp1[v];
            }
        }
    }

    dp2[node] = max(dp1[node],val[node]+maxi1+maxi2);
}

void solve(){
   cin>>n;
   g.clear();
   g.resize(n+1);
   val.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
   for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
   }
   ans = 0;
   dp1.resize(n+1,0);
   dp2.resize(n+1,0);
   dfs(1,0);
   int ans = -1e9;
   for(int i=1;i<=n;i++){
    ans = max(ans,dp2[i]);
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