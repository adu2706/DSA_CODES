#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

void solve() {
    int q;
    cin >> q;
    multimap<string, int> multimp;

    while (q--) {
        string s;
        cin >> s;
        if (s == "add") {
            string x;
            int y;
            cin >> x >> y;
            multimp.insert(pair<string, int>(x, y));
        } else if (s == "erase") {
            string x;
            cin >> x;
            auto it = multimp.find(x);
            if (it != multimp.end()) {
                multimp.erase(it);
            }
        } else if (s == "eraseall") {
            string x;
            cin >> x;
            multimp.erase(x);
        } else {
            string x;
            cin >> x;
            if (multimp.find(x)!=multimp.end()) {
                cout<<multimp.find(x)->second<<endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
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
