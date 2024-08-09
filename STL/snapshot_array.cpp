#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct snapshot {
    int timer;
    map<int,vector<pair<int,int>>> arr;
    int n;
    snapshot(int length) {
        n = length;
        timer = 0;
    }

    void set(int index, int val) {
        while (!arr[index].empty() && arr[index].back().first == timer) {
            arr[index].pop_back();
        }
        arr[index].push_back({timer, val});
    }

    int snap() {
        timer++;
        return timer - 1;
    }

    int get(int index, int snap_id) {
        auto it = upper_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id, LLONG_MAX));
        if (it == arr[index].begin()) {
            return 0;
        } else {
            it--;
            return (*it).second;
        }
    }
};

void solve() {
    int q, l;
    cin >> q >> l;
    snapshot ss(l);

    while (q--) {
        string s;
        cin >> s;
        if (s == "set") {
            int idx, val;
            cin >> idx >> val;
            ss.set(idx, val);
        } else if (s == "snap") {
            cout << ss.snap() << endl;
        } else if (s == "get") {
            int idx, snap_id;
            cin >> idx >> snap_id;
            cout << ss.get(idx, snap_id) << endl;
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
