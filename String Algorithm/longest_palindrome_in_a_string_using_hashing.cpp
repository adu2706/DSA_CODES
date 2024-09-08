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

struct hasher {
    vector<int> fHash, rHash, pk;
    int sz, p, mod;

    void init(string s, int _p, int _mod) {
        sz = s.length();
        p = _p;
        mod = _mod;
        fHash.resize(sz);
        rHash.resize(sz);
        pk.resize(sz);
        pk[0] = 1;
        fHash[0] = s[0] - 'a' + 1;
        rHash[sz - 1] = s[sz - 1] - 'a' + 1;

        for (int i = 1; i < sz; i++) {
            fHash[i] = (1LL*fHash[i - 1] * p + s[i] - 'a' + 1) % mod;
            pk[i] = (1LL*pk[i - 1] * p) % mod;
        }

        for (int j = sz - 2; j >= 0; j--) {
            rHash[j] = (1LL*rHash[j + 1] * p + s[j] - 'a' + 1) % mod;
        }
    }

    int getfHash(int l, int r) {
        if (l == 0) {
            return fHash[r] % mod;
        } else {
            return ((fHash[r] - 1LL*fHash[l - 1] * pk[r - l + 1]) % mod + mod) % mod;
        }
    }

    int getrevHash(int l, int r) {
        if (r == sz - 1) {
            return rHash[l];
        } else {
            return ((rHash[l] - 1LL*rHash[r + 1] * pk[r - l + 1]) % mod + mod) % mod;
        }
    }
};


void solve() {
    string s;
    cin >> s;
    hasher h1, h2;
    h1.init(s, 37, 999999937);
    h2.init(s, 29, 999999931);

    int max_len = 0, start = 0;
    int sz = s.length();

    // Odd length palindromes
    for (int i = 0; i < sz; i++) {
        int lo = 1, hi = min(i + 1, sz - i), ans = 0;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (h1.getfHash(i - mid + 1, i) == h1.getrevHash(i, i + mid - 1) &&
                h2.getfHash(i - mid + 1, i) == h2.getrevHash(i, i + mid - 1)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        int cur_len = ans * 2 - 1;
        if (cur_len > max_len) {
            max_len = cur_len;
            start = i - ans + 1;
        }
    }

    // Even length palindromes
    for (int i = 0; i < sz; i++) {
        int lo = 1, hi = min(i + 1, sz - i - 1), ans = 0;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (h1.getfHash(i - mid + 1, i) == h1.getrevHash(i + 1, i + mid) &&
                h2.getfHash(i - mid + 1, i) == h2.getrevHash(i + 1, i + mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        int cur_len = ans * 2;
        if (cur_len > max_len) {
            max_len = cur_len;
            start = i - ans + 1;
        }
    }
    cout << s.substr(start, max_len) << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
