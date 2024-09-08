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
vector<int> indeg;
vector<int> topo;
int n, m;

void khan() {
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        topo.push_back(cur);
        for (auto v : g[cur]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                pq.push(v);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    g.clear();
    g.resize(n + 1);
    indeg.assign(n + 1, 0);
    topo.clear();

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
        indeg[a]++;
    }

    khan();
    int cnt = n;
    int hash[n+1];
    for (int i = 0; i < n; i++) {
        hash[topo[i]] = cnt--;
    }
    for(int i=1;i<=n;i++){
        cout<<hash[i]<<" ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
