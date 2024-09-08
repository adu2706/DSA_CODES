#include <bits/stdc++.h>
using namespace std;
#define int long long

struct segTree {
    vector<int> tree, lazy;
    vector<int> arr;
    
    void declaring(int n, vector<int> a) {
        tree.resize(4 * n + 400);
        lazy.resize(4 * n + 400, 0); // Initialize lazy array with 0
        arr = a;
    }

    void build(int index, int l, int r) {
        if (l == r) {
            tree[index] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        build(2 * index, l, mid);
        build(2 * index + 1, mid + 1, r);
        tree[index] = tree[2 * index] + tree[2 * index + 1];
    }

    void propagate(int index, int l, int r) {
        tree[index] += (r - l + 1) * lazy[index]; // Apply pending updates
        if (l != r) { // If not a leaf node, propagate to children
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        lazy[index] = 0; // Clear the lazy value
    }

    void update(int index, int l, int r, int st, int en, int val) {
        propagate(index, l, r);
        
        if (st > r || en < l) {
            return;
        }

        if (st <= l && r <= en) { // Current segment is fully within the range
            lazy[index] += val;
            propagate(index, l, r);
            return;
        }

        int mid = (l + r) / 2;
        update(2 * index, l, mid, st, en, val);
        update(2 * index + 1, mid + 1, r, st, en, val);
        tree[index] = tree[2 * index] + tree[2 * index + 1]; // Update the current node
    }

    int query(int index, int l, int r, int pos) {
        propagate(index, l, r);

        if (l == r) {
            return tree[index];
        }

        int mid = (l + r) / 2;
        if (pos <= mid) {
            return query(2 * index, l, mid, pos);
        } else {
            return query(2 * index + 1, mid + 1, r, pos);
        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    segTree st;
    st.declaring(n, a);
    st.build(1, 0, n - 1);

    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            // update
            int l, r, val;
            cin >> l >> r >> val;
            l--, r--;
            st.update(1, 0, n - 1, l, r, val);
        } else {
            // query
            int pos;
            cin >> pos;
            pos--;
            cout << st.query(1, 0, n - 1, pos) << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
