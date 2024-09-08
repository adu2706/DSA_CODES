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
vector<int> sz;
int n,k;
int dp[101][2][101];
//tc = O(n*n) beacuse use of sz vector
void dfs(int node, int par){
    //creating for child;
    for(int i=1;i<=n;i++){
        dp[node][1][i] = (i==1?val[node]:-1e9);
        dp[node][0][i] = (i==0?0:-1e9);
    }
    sz[node] = 1;
    for(auto v:g[node]){
        if(v!=par){
            dfs(v,node);
            for(int a=sz[node];a>=0;a--){
                for(int b=sz[v];b>=0;b--){
                    dp[node][0][a+b] = max(dp[node][0][a+b],dp[node][0][a]+max(dp[v][0][b],dp[v][1][b]));
                    dp[node][1][a+b] = max(dp[node][1][a+b],dp[node][1][a]+dp[v][0][b]);
                }
            }
            sz[node]+=sz[v];
        }
    }
}


void solve(){
    cin >> n >> k;
    g.clear();
    g.resize(n + 1);
    val.clear();
    val.resize(n + 1);
    memset(dp,0,sizeof(dp));

    for(int i = 1; i <= n; i++){
        cin >> val[i];
    }

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    cout<<max(dp[1][0][k],dp[1][1][k])<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
