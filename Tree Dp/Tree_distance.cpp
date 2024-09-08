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
vector<vector<int>> dp;
int ans = 0;
int n,k;
void dfs(int node, int par){
    dp[node][0] = 1;
    //dp[i][x] = no of nodes in this subtree at distance x
    for(auto v:g[node]){
        if(v!=par){
            dfs(v,node);
            //in the computed child(x) i want number of nodes at a distance dis-1 as that would 
            //be equal to a distance of dis from node
            for(int dis=1;dis<=k;dis++){
                ans+=1LL*dp[v][dis-1]*dp[node][k-dis];
            }
            for(int dis=1;dis<=k;dis++){
                dp[node][dis] += dp[v][dis-1];
            }
        }
    }
}

void solve(){
   cin>>n>>k;
   g.clear();
   g.resize(n+1);
   dp.clear();
   dp.resize(n+1,vector<int>(k+1,0));

   for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
   }
   ans = 0;
   dfs(1,0);
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