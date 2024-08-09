#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<int> a, b;
int n, m;
map<int, int> mp1, mp2;

int rec(int level, int curr_arr, int prevmove) {
    if (curr_arr == 1) {
        if (level == n) {
            return 0;
        }
    } else {
        if (level == m) {
            return 0;
        }
    }

    int ans = 0;
    if (curr_arr == 1) {
        if (prevmove == 0) {
            ans = max(ans, a[level] + rec(level + 1, 1, 0));
            if (mp2.find(a[level]) != mp2.end()) {
                ans = max(ans, rec(mp2[a[level]], 2, 1));
            }
        } else {
            ans = max(ans, a[level] + rec(level + 1, 1, 0));
        }
    } else {
        if (prevmove == 0) {
            ans = max(ans, b[level] + rec(level + 1, 2, 0));
            if (mp1.find(b[level]) != mp1.end()) {
                ans = max(ans, rec(mp1[b[level]], 1, 1));
            }
        } else {
            ans = max(ans, b[level] + rec(level + 1, 2, 0));
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    for (int i = n - 1; i >= 0; i--) {
        mp1[a[i]] = i;
    }

    cin >> m;
    b.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(b.begin(), b.end());
    for (int i = m - 1; i >= 0; i--) {
        mp2[b[i]] = i;
    }

    cout << max(rec(0, 1, 0), rec(0, 2, 0)) << endl;
    mp1.clear(), mp2.clear(), a.clear(), b.clear();
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
