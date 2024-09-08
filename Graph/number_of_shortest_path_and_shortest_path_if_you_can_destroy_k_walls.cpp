#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second

int mod = 1e9+7;
typedef pair<int, int> pii;

vector<vector<int>> g;
vector<vector<vector<int>>> vis, dis, num_path;
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

void bfs(int x, int y, int k) {
    vis.assign(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));
    dis.assign(n, vector<vector<int>>(m, vector<int>(k + 1, 1e9)));
    num_path.assign(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));

    queue<pair<pii, int>> q;
    dis[x][y][0] = 0;
    num_path[x][y][0] = 1;
    q.push({{x, y}, 0});

    while (!q.empty()) {
        auto v = q.front();
        int i = v.F.F;
        int j = v.F.S;
        int walls = v.S;
        q.pop();

        if (vis[i][j][walls]) {
            continue;
        }
        vis[i][j][walls] = 1;

        for (auto neigh : neighbours(i, j)) {
            int new_walls = walls + g[neigh.F][neigh.S];
            if (new_walls > k) {
                continue;
            }

            if (dis[neigh.F][neigh.S][new_walls] > dis[i][j][walls] + 1) {
                dis[neigh.F][neigh.S][new_walls] = dis[i][j][walls] + 1;
                num_path[neigh.F][neigh.S][new_walls] = num_path[i][j][walls];
                q.push({neigh, new_walls});
            } else if (dis[neigh.F][neigh.S][new_walls] == dis[i][j][walls] + 1) {
                num_path[neigh.F][neigh.S][new_walls] += num_path[i][j][walls];
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
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
                g[i][j] = 1;
            } else {
                g[i][j] = 0;
            }
        }
    }

    bfs(sc.F, sc.S, k);
    int min_dis = 1e9;
    for(int i = 0; i <= k; i++) {
        min_dis = min(min_dis, dis[en.F][en.S][i]);
    }

    if (min_dis == 1e9) {
        cout << -1 << endl;  // No valid path found
    } else {
        cout << min_dis << endl;
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
