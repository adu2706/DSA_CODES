#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second
#define INF 10000
#define endl '\n'

const int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

const int maxi = 1e6 + 10;
int dp[maxi][2];

class Solution {
public:
    int MOD = 1'000'000'007;
    unordered_map<int, long> f_cache;  
    unordered_map<int, long> p_cache;  
    
    long p(int n) {  
        if (p_cache.find(n) != p_cache.end()) {
            return p_cache[n];
        }
        long val;
        if (n == 2) {
            val = 1L;
        } else {
            val = (p(n - 1) + f(n - 2)) % MOD;
        }
        p_cache[n] = val;
        return val;
    }
    
    long f(int n) {  
        if (f_cache.find(n) != f_cache.end()) {
            return f_cache[n];
        }
        long val;
        if (n == 1) {
            val = 1L;
        } else if (n == 2) {
            val = 2L;
        } else {
            val = (f(n - 1) + f(n - 2) + 2 * p(n - 1)) % MOD;
        }
        f_cache[n] = val;
        return val;
    }
    
    int numTilings(int n) {
        return static_cast<int>(f(n));
    }
};

void solve() {
    int n;
    cin >> n;
    Solution solution;
    cout << solution.numTilings(n) << endl;
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

    return 0;
}
