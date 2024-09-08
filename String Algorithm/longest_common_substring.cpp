#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct hashing {
    vector<int> hash;
    vector<int> pk;
    int p;
    int mod;
    int n;

    void init(string s, int _p, int _mod) {
        n = s.length();
        p = _p;
        mod = _mod;
        hash.resize(n);
        pk.resize(n);
        hash[0] = s[0] - 'a' + 1;
        pk[0] = 1;
        for (int i = 1; i < n; i++) {
            hash[i] = (hash[i - 1] * p + (s[i] - 'a' + 1)) % mod;
            pk[i] = (pk[i - 1] * p) % mod;
        }
    }

    int get_hash(int l, int r) {
        if (l == 0) return hash[r];
        return (hash[r] - hash[l - 1] * pk[r - l + 1] % mod + mod) % mod;
    }

    unordered_set<int> substring_hashing(int len) {
        unordered_set<int> hashes;
        for (int i = 0; i + len - 1 < n; i++) {
            hashes.insert(get_hash(i, i + len - 1));
        }
        return hashes;
    }
};

bool check(string s1, string s2, int len) {
    hashing hs1, hs2;
    hs1.init(s1, 31, 1e9 + 7);
    hs2.init(s2, 31, 1e9 + 7);

    unordered_set<int> hash_set_s1 = hs1.substring_hashing(len);

    for (int i = 0; i + len - 1 < s2.length(); i++) {
        int hash_s2 = hs2.get_hash(i, i + len - 1);
        if (hash_set_s1.find(hash_s2) != hash_set_s1.end()) {
            return true;
        }
    }
    return false;
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.length() < s2.length()) {
        swap(s1, s2);
    }
    int n1 = s1.length();
    int n2 = s2.length();

    int lo = 1;
    int hi = n2;

    int ans = 0;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(s1, s2, mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << endl;
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
