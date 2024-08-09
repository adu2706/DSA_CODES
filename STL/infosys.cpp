#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

string s, t;
int n, m, k;
vector<vector<vector<int>>> dp;

int rec(int i, int j, int k) {
    if (j == m) {
        return 1+rec(i,0,k);
    }
    if (i == n) { 
        return 0;
    }
    if (dp[i][j][k] != -1) {
        return dp[i][j][k];
    }

    int ans = rec(i+1, j, k); 

    if (s[i] == t[j]) {
        ans = max(ans,rec(i + 1, j + 1, k)); 
    } else if (k > 0) { 
        ans = max(ans,rec(i + 1, j + 1, k - 1));
    }

    return dp[i][j][k] = ans;
}

void solve() {
    cin >> n >> m >> k;
    cin >> s >> t;
    
    // Initialize dp array with -1
    dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
    cout << rec(0, 0, k) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
    return 0;
}
