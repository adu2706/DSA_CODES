#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 10000

vector<vector<int>> g;
vector<int> val;
int indp[200200];
int ans[200200];
int dep[200200];
int sum;
int total;

void in_dfs(int node, int par, int depth) {
    indp[node] = val[node];
    dep[node] = depth;
    for (auto v : g[node]) {
        if (v != par) {
            in_dfs(v, node, depth + 1);
            indp[node] += indp[v];
        }
    }
}

void dfs(int node, int par) {
    for (auto v : g[node]) {
        if (v != par) {
            ans[v] = ans[node] + 1*(sum-indp[v]) -1*(indp[v]);
            dfs(v, node);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    g.clear();
    g.resize(n + 1);
    val.clear();
    val.resize(n + 1);
    memset(indp, 0, sizeof(indp[0]) * (n + 1));
    memset(ans, 0, sizeof(ans[0]) * (n + 1));
    memset(dep, 0, sizeof(dep[0]) * (n + 1));
    sum = 0;

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        sum += val[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    in_dfs(1, 0, 0);

    total = 0;
    for (int i = 1; i <= n; i++) {
        total += dep[i] * val[i];
    }

    ans[1] = total;
    dfs(1, 0);

    int min_cost = LLONG_MAX;
    int max_cost = LLONG_MIN;

    for (int i = 1; i <= n; i++) {
        min_cost = min(min_cost, ans[i]);
        max_cost = max(max_cost, ans[i]);
    }

    cout << max_cost << " " << min_cost << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
