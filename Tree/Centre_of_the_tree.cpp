#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 10000
#define F first
#define S second

int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int dep[200200];
int par[200200];
vector<int> g[200200];

void dfs(int node, int parent, int depth) {
    dep[node] = depth;
    par[node] = parent;
    
    for (auto v : g[node]) {
        if (v != parent) {
            dfs(v, node, depth + 1);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    
    // Clear previous graph data if running multiple test cases
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        dep[i] = 0;
        par[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // First DFS to find the farthest node from node 1
    dfs(1, 0, 0);
    int mach1 = 1;
    for (int i = 1; i <= n; i++) {
        if (dep[i] > dep[mach1]) {
            mach1 = i;
        }
    }

    // Second DFS to find the farthest node from mach1 (this gives us the diameter)
    dfs(mach1, 0, 0);
    int mach2 = 1;
    for (int i = 1; i <= n; i++) {
        if (dep[i] > dep[mach2]) {
            mach2 = i;
        }
    }

    int diameter = dep[mach2];

    if (diameter % 2 == 0) {
        // Only 1 center exists
        int centre;
        int node = mach2;
        int depth = 1;
        while (depth <= diameter / 2) {
            node = par[node];
            depth++;
        }
        centre = node;
        cout << "Centre 1: " << centre<< endl;
    } else {
        // 2 centers exist
        int centre1, centre2;
        int node = mach2;
        int depth = 1;
        while (depth <= diameter / 2) {
            node = par[node];
            depth++;
        }
        centre1 = node;
        centre2 = par[node];
        cout << "Centre 1: " << centre1 << " , " << "Centre 2: " << centre2 << endl;
        cout<<-1<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
