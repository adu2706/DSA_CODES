#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second

int mod = 1e9+7;
typedef pair<int, int> pii;

vector<vector<int>> g;
vector<vector<int>> vis, dis, num_path;
int n, m, k;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

vector<pii> neighbours(int x, int y) {
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

void bfs01(int x, int y) {
    vis.assign(n, vector<int>(m, 0));
    dis.assign(n, vector<int>(m, 1e9));
    num_path.assign(n, vector<int>(m, 0));

    deque<pii> dq;
    dis[x][y] = 0;
    num_path[x][y] = 1;
    dq.push_back({x, y});

    while (!dq.empty()) {
        auto v = dq.front();
        int i = v.F;
        int j = v.S;
        dq.pop_front();

        if (vis[i][j]) {
            continue;
        }
        vis[i][j] = 1;

        for (auto neigh : neighbours(i, j)) {
            int weight = g[neigh.F][neigh.S];
            if (dis[neigh.F][neigh.S] > dis[i][j] + weight) {
                dis[neigh.F][neigh.S] = dis[i][j] + weight;
                num_path[neigh.F][neigh.S] = num_path[i][j]; // new shortest path found
                if (weight == 0) {
                    dq.push_front(neigh);
                } else {
                    dq.push_back(neigh);
                }
            } else if (dis[neigh.F][neigh.S] == dis[i][j] + weight) {
                num_path[neigh.F][neigh.S] += num_path[i][j]; // additional shortest path
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    g.assign(n, vector<int>(m, 0));
    pii sc, en;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if (ch == 'S') {
                sc = {i, j};
            } else if (ch == 'F') {
                en = {i, j};
            }
            if (ch == '#') {
                g[i][j] = 1; // wall has weight 1
            } else {
                g[i][j] = 0; // empty space has weight 0
            }
        }
    }

    bfs01(sc.F, sc.S);
    int min_wall = dis[en.F][en.S];

    if (min_wall == 1e9) {
        cout << -1 << endl;  // No valid path found
    } else {
        cout << min_wall << endl;
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
