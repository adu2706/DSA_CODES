#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct segtree {
    vector<pair<int,pair<int,int>>> tree;
    string s;

    void declare(string str) {
        s = str;
        int n = str.length();
        tree.resize(4*n+400);
    }

    pair<int,pair<int,int>> merge(pair<int,pair<int,int>> x, pair<int,pair<int,int>> y) {
        pair<int,pair<int,int>> res;
        int len = x.first + y.first;
        int openbrac = x.second.first;
        int closebrac = y.second.second;

        int matched = min(openbrac, closebrac);
        len += matched;

        res = {len, {x.second.first - matched + y.second.first, x.second.second + y.second.second - matched}};
        return res;
    }

    void build(int index, int l, int r) {
        if (l == r) {
            if (s[l] == '(') {
                tree[index] = {0, {1, 0}};
            } else {
                tree[index] = {0, {0, 1}};
            }
            return;
        }

        int mid = (l + r) / 2;
        build(2 * index, l, mid);
        build(2 * index + 1, mid + 1, r);
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }

    pair<int,pair<int,int>> query(int index, int l, int r, int st, int en) {
        if (st > r || en < l) {
            return {0, {0, 0}};
        }

        if (st <= l && r <= en) {
            return tree[index];
        }

        int mid = (l + r) / 2;
        auto left_query = query(2 * index, l, mid, st, en);
        auto right_query = query(2 * index + 1, mid + 1, r, st, en);

        return merge(left_query, right_query);
    }
};

void solve() {
    string s;
    cin >> s;

    segtree st;
    st.declare(s);
    st.build(1, 0, s.length() - 1);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        //lenght = total matched multiply by two because every two match make length 2;
        cout << st.query(1, 0, s.length() - 1, l, r).first * 2 << endl;
    }
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
