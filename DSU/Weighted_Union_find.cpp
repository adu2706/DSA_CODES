#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct weight_DSU {
    vector<int> par;
    vector<int> wt;
    vector<int> sz;
    int comp_number;

    void declare(int n) {
        par.resize(n + 1);
        wt.resize(n + 1);
        sz.resize(n + 1);
        comp_number = n;
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            wt[i] = 0;
            sz[i] = 1;
        }
    }

    pair<int, int> find(int x) {
        if(par[x]==x){
            return {par[x],wt[x]};
        }else{
            auto u = find(par[x]);
            wt[x] += u.second;
            par[x] = u.first;
            return {par[x], wt[x]};
        }
    }

    void merge(int x, int y, int w) {
        auto p = find(x);
        auto q = find(y);

        int xroot = p.first;
        int xweight = p.second;

        int yroot = q.first;
        int yweight = q.second;

        if (xroot != yroot) {
            if (sz[xroot] > sz[yroot]) {
                par[yroot] = xroot;
                wt[yroot] = xweight - yweight - w;
                sz[xroot] += sz[yroot];
            } else {
                par[xroot] = yroot;
                wt[xroot] = yweight - xweight + w;
                sz[yroot] += sz[xroot];
            }
            comp_number--;
        }
    }

    int get_comp() {
        return comp_number;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    weight_DSU dsu;

    dsu.declare(n);

    while (q--) {
        int ch;
        cin >> ch;
        if (ch == 0) {
            int y, x, z;
            cin >> y >> x >> z;
            if (dsu.find(x).first != dsu.find(y).first) {
                dsu.merge(x, y, z);
            }
        } else {
            int y, x;
            cin >> y >> x;
            if (dsu.find(x).first != dsu.find(y).first) {
                cout << '?' << endl;
            } else {
                cout << dsu.find(x).second - dsu.find(y).second << endl;
            }
        }
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
