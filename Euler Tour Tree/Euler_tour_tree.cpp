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
vector<pair<int,int>> arr1, arr2; // arr1 for subtree type query, arr2 for path query
vector<int> val;

void dfs(int node, int parent) {
    arr1.push_back({node, val[node]});
    arr2.push_back({node, val[node]});
    for(auto v: g[node]) {
        if(v != parent) {
            dfs(v, node);
        }
    }
    arr2.push_back({-node, -val[node]});
    arr1.push_back({-node, 0});
}

struct SegTree1 {
    //Subtree queries
    vector<int> segT1;

    void declare(int n) {
        segT1.resize(4*n);
    }

    void build(int index, int l, int r) {
        if(l == r) {
            segT1[index] = arr1[l].second;
            return;
        }
        int mid = (l+r)/2;
        
        build(2*index, l, mid);
        build(2*index+1, mid+1, r);

        segT1[index] = segT1[2*index] + segT1[2*index+1];
    }

    void update(int index, int l, int r, int pos, int val) {
        if(pos < l || pos > r) {
            return;
        }

        if(l == r) {
            arr1[l].second = val;
            segT1[index] = arr1[l].second;
            return;
        }

        int mid = (l+r)/2;
        
        update(2*index, l, mid, pos, val);
        update(2*index+1, mid+1, r, pos, val);

        segT1[index] = segT1[2*index] + segT1[2*index+1];
    }

    int query(int index, int l, int r, int st, int en) {
        if(st > r || en < l) {
            return 0;
        }
        if(st <= l && r <= en) {
            return segT1[index];
        }

        int mid = (l+r)/2;

        return query(2*index, l, mid, st, en) + query(2*index+1, mid+1, r, st, en);
    }
};

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
    int n;
    cin >> n;
    g.clear();
    g.resize(n+1);
    val.clear();
    val.resize(n+1);
    arr1.clear();
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
    for(int i = 0; i < arr1.size(); i++) {
        idx[arr1[i].first] = i;
    }

    SegTree1 st1;
    SegTree2 st2;
    
    int m = arr1.size();
    st1.declare(m);
    st2.declare(m);
    st1.build(1, 0, m-1);
    st2.build(1, 0, m-1);

    int q;
    cin >> q;

    while(q--) {
        int ch;
        cin >> ch;
        if(ch == 1) {
            // Sum of subtree of node 'x'
            int x;
            cin >> x;
            int st = idx[x];
            int en = idx[-x];
            cout << st1.query(1, 0, m-1, st, en) << endl;
        } else if(ch == 2) {
            // Update val at node x to y
            int x, y;
            cin >> x >> y;
            int inpos = idx[x];
            int outpos = idx[-x];
            st1.update(1, 0, m-1, inpos, y);
            st2.update(1, 0, m-1, inpos, y);
            st2.update(1, 0, m-1, outpos, -y);
        } else if(ch == 3) {
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
