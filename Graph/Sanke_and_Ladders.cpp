#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 10000
typedef pair<int, int> pii;

vector<vector<int>> g;
vector<int> direct, vis, dis;

void bfs(int sc) {
    dis.assign(101, 1e18);
    vis.assign(101, 0);

    queue<int> q;
    dis[sc] = 0;
    q.push(sc);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (vis[cur] == 1) continue;
        vis[cur] = 1;

        if (direct[cur] != cur) {
            if (dis[direct[cur]] > dis[cur]) {
                dis[direct[cur]] = dis[cur];
                q.push(direct[cur]);
            }
        } else {
            for (auto v : g[cur]) {
                if (dis[v] > dis[cur] + 1) {
                    dis[v] = dis[cur] + 1;
                    q.push(v);
                }
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    direct.resize(101);
    g.resize(101);
    for (int i = 1; i <= 100; i++) {
        direct[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        direct[a] = b;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        direct[a] = b;
    }

    for(int i=1;i<=100;i++){
        for(int j=1;j<=6;j++){
            if(i+j<=100){
                g[i].push_back(i+j);
            }
        }
    }

    bfs(1);
    int en = 100;
    if (dis[en] == 1e18) {
        cout << -1 << endl;
    } else {
        cout << dis[en] << endl;
    }
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
}
