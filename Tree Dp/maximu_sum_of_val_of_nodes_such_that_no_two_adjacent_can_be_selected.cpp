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
vector<vector<int>> dp;

void dfs(int node, int par){
    // 1 means take
    // 2 means not take
    dp[node][1] = val[node];
    dp[node][0] = 0;

    for(auto v:g[node]){
        if(v!=par){
            dfs(v,node);
            dp[node][1] += dp[v][0];
            dp[node][0] += max(dp[v][0],dp[v][1]);
        }
    }
}


void solve(){
    int n;
    cin >> n;
    g.clear();
    g.resize(n + 1);
    val.clear();
    val.resize(n + 1);
    dp.clear();
    dp.resize(n + 1, vector<int>(2, 0));

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
    cout<<max(dp[1][0],dp[1][1])<<endl;
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
