#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int dp[200200][25];
int n, m;
vector<vector<int>> g;

int dfs(int node, int par, int gc) {
    if(dp[node][gc] != -1) return dp[node][gc];
    
    int ans = 0;
    for(int color = 1; color <= m; color++) {
        int temp = 1;
        int cnt_child = 0;
        
        for(auto v : g[node]) {
            if(v != par) {
                cnt_child++;
                temp = (temp * dfs(v, node, gcd(gc, color)));
            }
        }
        
        if(cnt_child == 0) { // Leaf node case
            if(gcd(gc, color) == 1) {
                ans = ans + temp;
            }
        } else {
            ans = ans + temp;
        }
    }
    
    return dp[node][gc] = ans;
}

void solve() {
    cin >> n >> m;
    g.resize(n + 1);
    memset(dp, -1, sizeof(dp));
    
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    cout << dfs(1, 0, 0) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}
