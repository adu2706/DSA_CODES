#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct node {
    int mxsum;
    int lsum;
    int rsum;
    int tsum;
    node() {
        lsum = 0;
        rsum = 0;
        mxsum = 0;
        tsum = 0;
    }
};

struct segtree {
    vector<node> t;
    vector<int> arr;

    void declare(int n, vector<int>& a) {
        arr = a;
        t.resize(4*n + 400);
    }

    void merge(node& t1, node& t2, node& t3) {
        t1.mxsum = max({t2.mxsum, t3.mxsum, t2.rsum + t3.lsum});
        t1.lsum = max(t2.lsum, t2.tsum + t3.lsum);
        t1.rsum = max(t3.rsum, t3.tsum + t2.rsum);
        t1.tsum = t2.tsum + t3.tsum;
    }

    void build(int index, int l, int r) {
        if (l == r) {
            t[index].mxsum = max(0LL, arr[l]);
            t[index].lsum = max(0LL, arr[l]);
            t[index].rsum = max(0LL, arr[l]);
            t[index].tsum = arr[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2*index, l, mid);
        build(2*index + 1, mid + 1, r);
        merge(t[index], t[2*index], t[2*index + 1]);
    }

    void update(int index, int l, int r, int pos, int val) {
        if (pos < l || pos > r) {
            return;
        }

        if (l == r) {
            arr[l] = val;
            t[index].mxsum = max(0LL, arr[l]);
            t[index].lsum = max(0LL, arr[l]);
            t[index].rsum = max(0LL, arr[l]);
            t[index].tsum = arr[l];
            return;
        }

        int mid = (l + r) / 2;

        update(2*index, l, mid, pos, val);
        update(2*index + 1, mid + 1, r, pos, val);
        merge(t[index], t[2*index], t[2*index + 1]);
    }

    node query(int index, int l, int r, int st, int en) {
        if (st > r || en < l) {
            return node(); 
        }

        if (st <= l && r <= en) {
            return t[index];
        }

        int mid = (l + r) / 2;

        node left = query(2*index, l, mid, st, en);
        node right = query(2*index + 1, mid + 1, r, st, en);

        node result;
        merge(result, left, right);
        return result;
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
        int pos, val;
        cin >> pos >> val;
        pos--;
        sg.update(1, 0, n - 1, pos, val);
        cout << sg.query(1, 0, n - 1, 0, n - 1).mxsum << endl;
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
