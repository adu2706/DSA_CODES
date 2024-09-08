#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct RDSU {
    vector<int> par;
    vector<int> sz;
    vector<pair<int,int>> st;
    multiset<int> compsz;

    void declare(int n) {
        par.resize(1000100);
        sz.resize(1000100);
        compsz.clear();

        for (int i = 0; i < 1000100; i++) {
            par[i] = i;
            sz[i] = 1;
            compsz.insert(1);
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        return find(par[x]);
    }

    void merge(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);

        if (xroot != yroot) {
            if (sz[xroot] < sz[yroot]) {
                swap(xroot, yroot);
            }
            compsz.erase(compsz.find(sz[xroot]));
            compsz.erase(compsz.find(sz[yroot]));
            sz[xroot] += sz[yroot];
            par[yroot] = xroot;
            st.push_back({yroot, xroot});
            compsz.insert(sz[xroot]);
        }
    }

    void rollback() {
        while (!st.empty()) {
            int initialpar = st.back().F;
            int finalpar = st.back().S;
            st.pop_back();
            compsz.erase(compsz.find(sz[finalpar]));
            par[initialpar] = initialpar;
            sz[finalpar] -= sz[initialpar];
            compsz.insert(sz[initialpar]);
            compsz.insert(sz[finalpar]);
        }
    }

    int getmax() {
        auto it = compsz.end();
        it--;
        return *it;
    }
};

vector<vector<int>> arr, node;
vector<pair<pair<int,int>,pair<int,int>>> edge;
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int n, m;

bool check(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return 0;
    }
    return 1;
}

void solve() {
    cin >> n >> m;
    RDSU dsu;
    dsu.declare(n * m + 1);
    int cnt = 1;
    arr = vector<vector<int>>(n+1,vector<int>(m+1,0));
    node = vector<vector<int>>(n+1,vector<int>(m+1,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            node[i][j] = cnt++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 2; k++) {
                int xx = i + dx[k];
                int yy = j + dy[k];
                if (check(xx, yy)) {
                    int cc1 = arr[i][j];
                    int cc2 = arr[xx][yy];
                    if (cc1 > cc2) swap(cc1, cc2);
                    if (cc1 != cc2) {
                        edge.push_back({{cc1, cc2}, {node[i][j], node[xx][yy]}});
                    } else {
                        dsu.merge(node[i][j], node[xx][yy]);
                    } 
                }
            }
        }
    }

    dsu.st.clear();
    sort(edge.begin(), edge.end());
    int ans = dsu.getmax();

    for (int i = 0; i < edge.size(); i++) {
        int j = i;
        while (j < edge.size() && edge[i].F == edge[j].F) {
            dsu.merge(edge[j].S.F, edge[j].S.S);
            j++;
        }
        ans = max(ans, dsu.getmax());
        dsu.rollback();
        i = j - 1;
    }

    cout << ans << endl;
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
