#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000

int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int cal(int mask, vector<vector<int>> v) {
    int eff = 0;
    int n = v.size();
    for(int i = 0; i < n; i++) {
        if(mask & (1 << i)) {
            for(int j = i + 1; j < n; j++) {
                if(mask & (1 << j)) {
                    eff += v[i][j];
                }
            }
        }
    }
    return eff;
}

int fun(int n, vector<vector<int>> v) {
    int mask = 1 << n;
    vector<int> ans(mask, 0);
    
    for(int i = 1; i < mask; i++) {
        ans[i] = cal(i, v);
    }

    for(int i = 1; i < mask; i++) {
        for(int submask = i; submask ; submask = (submask - 1) & i) {
            ans[i] = max(ans[i], ans[submask] + ans[submask ^ i]);
        }
    }

    return ans[mask - 1];
}











void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    int ans = fun(n, v);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}
