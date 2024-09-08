#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node {
    pair<int, int> p;
};

struct segtree {
    vector<node> t;
    vector<int> arr;

    void declare(int n, vector<int> a) {
        arr = a;
        t.resize(4 * n + 400);
    }

    pair<int, int> merge(pair<int, int> x, pair<int, int> y) {
        pair<int, int> ans;
        if (x.first == y.first) {
            ans = {x.first, x.second + y.second};
        } else if (x.first < y.first) {
            ans = x;
        } else {
            ans = y;
        }
        return ans;
    }

    void build(int index, int l, int r) {
        if (l == r) {
            t[index].p.first = arr[l];
            t[index].p.second = 1;
            return;
        }
        int mid = (l + r) / 2;

        build(2 * index, l, mid);
        build(2 * index + 1, mid + 1, r);
        t[index].p = merge(t[2 * index].p, t[2 * index + 1].p);
    }

    void update(int index, int l, int r, int pos, int val) {
        if (pos < l || pos > r) {
            return;
        }

        if (l == r) {
            t[index].p = {val, 1};
            return;  
        }

        int mid = (l + r) / 2;

        update(2 * index, l, mid, pos, val);
        update(2 * index + 1, mid + 1, r, pos, val);

        t[index].p = merge(t[2 * index].p, t[2 * index + 1].p);
    }

    pair<int, int> query(int index, int l, int r, int st, int en) {
        if (en < l || st > r) {
            return {1e18, 0};  
        }

        if (st <= l && r <= en) {
            return t[index].p;
        }

        int mid = (l + r) / 2;

        return merge(query(2 * index, l, mid, st, en), query(2 * index + 1, mid + 1, r, st, en));
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    segtree sg;
    sg.declare(n, arr);
    sg.build(1, 0, n - 1);

    while (q--) {
        int ch;
        cin >> ch;
        if (ch == 1) {
            // update
            int pos, val;
            cin >> pos >> val;
            pos--;
            sg.update(1, 0, n - 1, pos, val);
        } else {
            // query
            int l, r;
            cin >> l >> r;
            l--, r--;
            pair<int, int> ans = sg.query(1, 0, n - 1, l, r);
            cout << ans.first << " " << ans.second << endl;
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
