#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

struct Hashing {
    vector<int> fhash;
    vector<int> pk;
    int sz;
    int p;
    int mod;

    void init(string s, int _p, int _mod) {
        p = _p;
        mod = _mod;
        sz = s.length();
        fhash.resize(sz);
        pk.resize(sz);

        fhash[0] = s[0] - 'a' + 1;
        pk[0] = 1;

        for (int i = 1; i < sz; i++) {
            fhash[i] = (fhash[i - 1] * p + (s[i] - 'a' + 1)) % mod;
            pk[i] = (pk[i - 1] * p) % mod;
        }
    }

    int getHash(int l, int r) {
        if (l == 0) {
            return fhash[r];
        } else {
            return ((fhash[r] - fhash[l - 1] * pk[r - l + 1]) % mod + mod) % mod;
        }
    }
};

void solve() {
    string pattern, text;
    cin >> pattern >> text;

    Hashing pat, txt;
    pat.init(pattern, 31, 1e9 + 7);
    txt.init(text, 31, 1e9 + 7);

    int p = pattern.length();
    int hashp = pat.getHash(0, p - 1);
    for (int i = 0; i + p - 1 < text.length(); i++) {
        if (hashp == txt.getHash(i, i + p - 1)) {
            cout << "Match at: " << i << endl;
        }
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
