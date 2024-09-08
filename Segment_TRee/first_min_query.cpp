#include <bits/stdc++.h>
using namespace std;
#define int long long
 
struct segtree {
    vector<int> t;
    vector<int> arr;
    int n;
 
    void declare(int nn, vector<int> a) {
        arr = a;
        n = nn;
        t.resize(4 * n + 10);
    }
 
    void build(int index, int l, int r) {
        if (l == r) {
            t[index] = arr[l];
            return;
        }
 
        int mid = (l + r) / 2;
 
        build(2 * index, l, mid);
        build(2 * index + 1, mid + 1, r);
        t[index] = max(t[2 * index], t[2 * index + 1]);
    }
 
    void update(int index, int l, int r, int pos, int val) {
        if (pos < l || pos > r) {
            return;
        }
 
        if (l == r) {
            t[index] -= val;
            return;
        }
 
        int mid = (l + r) / 2;
 
        update(2 * index, l, mid, pos, val);
        update(2 * index + 1, mid + 1, r, pos, val);
 
        t[index] = max(t[2 * index], t[2 * index + 1]);
    }
 
    int query(int index, int l, int r, int room) {
        if (t[index] < room) {
            return -1;
        }
        if (l == r) {
            return l;
        }
 
        int mid = (l + r) / 2;
        if (t[2 * index] >= room) {
            return query(2 * index, l, mid, room);
        } else {
            return query(2 * index + 1, mid + 1, r, room);
        }
    }
};
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
 
    segtree st;
    st.declare(n, v);
    st.build(1, 0, n - 1);
 
    while (m--) {
        int room;
        cin >> room;
        int x = st.query(1, 0, n - 1, room);
        if (x != -1) {
            st.update(1, 0, n - 1, x, room);
            x += 1;  
        } else {
            x = 0;
        }
        cout << x << " ";
    }
    cout << endl;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}