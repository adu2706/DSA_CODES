#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
#define endl '\n'
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<vector<int>> g;
vector<pair<int,int>> arr2; // arr2 for path query
vector<int> val;

void dfs(int node, int parent) {
    arr2.push_back({node, val[node]});
    for(auto v: g[node]) {
        if(v != parent) {
            dfs(v, node);
        }
    }
    arr2.push_back({-node, -val[node]});
}


struct SegTree2 {
    //path from root to any node type queries
    vector<int> segT2;

    void declare(int n) {
        segT2.resize(4*n);
    }

    void build(int index, int l, int r) {
        if(l == r) {
            segT2[index] = arr2[l].second;
            return;
        }
        int mid = (l+r)/2;
        
        build(2*index, l, mid);
        build(2*index+1, mid+1, r);

        segT2[index] = segT2[2*index] + segT2[2*index+1];
    }

    void update(int index, int l, int r, int pos, int val) {
        if(pos < l || pos > r) {
            return;
        }

        if(l == r) {
            arr2[l].second = val;
            segT2[index] = arr2[l].second;
            return;
        }

        int mid = (l+r)/2;
        
        update(2*index, l, mid, pos, val);
        update(2*index+1, mid+1, r, pos, val);

        segT2[index] = segT2[2*index] + segT2[2*index+1];
    }

    int query(int index, int l, int r, int st, int en) {
        if(st > r || en < l) {
            return 0;
        }
        if(st <= l && r <= en) {
            return segT2[index];
        }

        int mid = (l+r)/2;

        return query(2*index, l, mid, st, en) + query(2*index+1, mid+1, r, st, en);
    }
};

void solve() {
    int n,q;
    cin >> n >>q;
    g.clear();
    g.resize(n+1);
    val.clear();
    val.resize(n+1);
    arr2.clear();
    for(int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);

    map<int, int> idx;
    for(int i = 0; i < arr2.size(); i++) {
        idx[arr2[i].first] = i;
    }

    SegTree2 st2;
    
    int m = arr2.size();
    st2.declare(m);
    st2.build(1, 0, m-1);

    while(q--) {
        int ch;
        cin >> ch;
        if(ch == 1) {
            // Update val at node x to y
            int x, y;
            cin >> x >> y;
            int inpos = idx[x];
            int outpos = idx[-x];
            st2.update(1, 0, m-1, inpos, y);
            st2.update(1, 0, m-1, outpos, -y);
        } else if(ch == 2) {
            // Sum of val of node between path root and node x;
            int x;
            cin >> x;
            int inpos = idx[x];
            cout << st2.query(1, 0, m-1, 0, inpos) << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}
