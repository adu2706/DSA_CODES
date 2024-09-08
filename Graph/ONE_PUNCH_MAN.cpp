#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 1e9
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<string> g;
vector<vector<int>> vis;
vector<vector<int>> dis;
int n, m;

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

bool check(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    return true;
}

vector<pii> neigh1(int x, int y) {
    vector<pii> ans;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (check(nx, ny)) {
            ans.push_back({nx, ny});
        }
    }
    return ans;
}

vector<pii> neigh2(int x, int y) {
    vector<pii> ans;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (check(nx, ny)) {
            ans.push_back({nx, ny});
        }
    }
    return ans;
}

void bfs01(int x, int y) {
    vis.assign(n, vector<int>(m, 0));
    dis.assign(n, vector<int>(m, 1e18));  

    deque<pii> dq;
    dis[x][y] = 0;
    dq.push_back({x, y});

    while (!dq.empty()) {
        auto cur = dq.front();
        dq.pop_front();

        if (vis[cur.F][cur.S]) {
            continue;
        }
        vis[cur.F][cur.S] = 1;

        for (auto v : neigh1(cur.F, cur.S)) {
            if (g[v.F][v.S] == '#') {
                for (auto u : neigh2(v.F, v.S)) {
                    if (u.F != cur.F || u.S != cur.S) {
                        if (dis[u.F][u.S] > dis[cur.F][cur.S] + 1) {
                            dis[u.F][u.S] = dis[cur.F][cur.S] + 1;
                            dq.push_back(u);
                        }
                    }
                }
            } else {
                if (dis[v.F][v.S] > dis[cur.F][cur.S]) {
                    dis[v.F][v.S] = dis[cur.F][cur.S];
                    dq.push_front(v);
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    bfs01(0, 0);

    if (dis[n - 1][m - 1] == 1e18) {
        cout << -1 << endl;
    } else {
        cout << dis[n - 1][m - 1] << endl;
    }
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
