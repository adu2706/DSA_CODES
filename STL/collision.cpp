#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> arr(n);
    vector<pii> brr(m);
   
    for(int i = 0; i < n; i++) {
        cin >> arr[i].F >> arr[i].S;
    }
    for(int i = 0; i < m; i++) {
        cin >> brr[i].F >> brr[i].S;
    }

    unordered_map<int, int> mp1;
    unordered_map<int, int> mp2;

    for(int i = 0; i < n; i++) {
        mp1[arr[i].F * arr[i].S]++;
    }

    for(int i = 0; i < m; i++) {
        mp2[brr[i].F * brr[i].S]++;
    }

    int ans = 0;
    for(auto &v : mp1) {
        int x = v.first;
        int y = v.second;
        if(mp2.find(x) != mp2.end()) {
            ans += min(mp1[x], mp2[x]);
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
