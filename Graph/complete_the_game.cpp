#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


vector<vector<int>> g,back_edge;
vector<int> indeg;
vector<int> topo;
vector<int> dp;
int n,m;
void khan(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    dp.resize(n+1,0);
    dp[1] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        topo.push_back(cur);
        int temp=0;
        for(auto v:g[cur]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(v);
                temp++;
            }
        }
        for(auto prev:back_edge[cur]){
            dp[cur] = (dp[cur]+dp[prev])%mod;
        }
    }
}
void solve(){
   cin>>n>>m;
   g.resize(n+1);
   back_edge.resize(n+1);
   indeg.assign(n+1,0);
   for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    back_edge[b].push_back(a);
    indeg[b]++;
   }
   khan();
   cout<<dp[n]<<endl;   
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