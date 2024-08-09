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
    int h, w, n;
    cin>> h >> w >> n;
    set<int> vert, horz;
    horz.insert(0);
    horz.insert(h);
    vert.insert(0);
    vert.insert(w);

    multiset<int> horz_cut, vert_cut;
    horz_cut.insert(h);
    vert_cut.insert(w);

    while (n--) {
        char ch;
        int x;
        cin >> ch >> x;
        if (ch == 'H') {
            horz.insert(x);
            auto it = horz.find(x);
            auto it1 = prev(it);
            auto it2 = next(it);

            horz_cut.erase(horz_cut.find(*it2 - *it1));
            horz_cut.insert(*it2 - *it);
            horz_cut.insert(*it - *it1);
        } else {
            vert.insert(x);
            auto it = vert.find(x);
            auto it1 = prev(it);
            auto it2 = next(it);

            vert_cut.erase(vert_cut.find(*it2 - *it1));
            vert_cut.insert(*it2 - *it);
            vert_cut.insert(*it - *it1);
        }
        cout << (*vert_cut.rbegin()) * (*horz_cut.rbegin()) << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
