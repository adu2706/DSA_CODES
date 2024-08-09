#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

using event = pair<pair<int, int>, pair<int, int>>;

// Type of events
// 0 -> start
// 1 -> query
// 2 -> end
void solve() {
    int n;
    cin >> n;
    vector<event> events;

    for (int i = 0; i < n; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        events.push_back({{l, 0}, {x, i}});
        events.push_back({{r, 2}, {x, i}});
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int y, k;
        cin >> y >> k;
        events.push_back({{y, 1}, {k, i}});
    }

    sort(events.begin(), events.end());

    vector<int> ans(q);
    multiset<int> mt;
    for (event v : events) {
        if (v.F.S == 0) {
            // Start of interval
            mt.insert(v.S.F);
        } else if (v.F.S == 1) {
            // Query
            int temp = 0;
            int cnt = 0;
            for (auto it = mt.rbegin(); it != mt.rend(); it++) {
                temp += *it;
                cnt++;
                if (cnt == v.S.F) {
                    break;
                }
            }
            ans[v.S.S] = temp;
        } else {
            // End of interval
            mt.erase(mt.find(v.S.F));
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
