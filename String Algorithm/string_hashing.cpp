#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct hasher{
    int sz, mod, p;
    vector<int> fHash, rHash;
    vector<int> pk;
    void init(string s, int _p, int _mod){
        mod = _mod;
        p = _p;
        sz = s.length();
        fHash.resize(sz);
        rHash.resize(sz);
        pk.resize(sz);
        fHash[0] = s[0] - 'a' + 1;
        rHash[sz - 1] = s[sz - 1] - 'a' + 1;
        pk[0] = 1;
        for (int i = 1; i < sz; i++) {
            fHash[i] = ((fHash[i - 1] % mod * p % mod) % mod + (s[i] - 'a' + 1) % mod) % mod;
            pk[i] = (pk[i - 1] % mod * p % mod) % mod;
        }
        for (int i = sz - 2; i >= 0; i--) {
            rHash[i] = ((rHash[i + 1] % mod * p % mod) % mod + (s[i] - 'a' + 1) % mod) % mod;
        }
    }

    int getfHash(int l, int r){
        // Convert 1-based to 0-based indexing
        l--, r--;
        if (l == 0) {
            return fHash[r];
        } else {
            return ((fHash[r] - fHash[l - 1] * pk[r - l + 1]) % mod + mod) % mod;
        }
    }

    int getrHash(int l, int r){
        // Convert 1-based to 0-based indexing
        l--, r--;
        if (r == sz - 1) {
            return rHash[l];
        } else {
            return ((rHash[l] - rHash[r + 1] * pk[r - l + 1]) % mod + mod) % mod;
        }
    }
};

void solve(){
    string s;
    cin >> s;
    hasher shash;
    shash.init(s, 37, 1e9 + 21);

    cout << shash.getfHash(2, 4) << " " << shash.getrHash(2, 4) << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
