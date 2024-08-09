#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct monotonicdq {
    deque<int> dq;

    void insert(int x) {
        while (!dq.empty() && dq.back() < x) {
            dq.pop_back();
        }
        dq.push_back(x);
    }

    void erase(int x) {
        if (!dq.empty() && dq.front() == x) {
            dq.pop_front();
        }
    }

    int get_max() {
        return dq.front();
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    monotonicdq mdq;
    for (int i = 0; i < k; i++) {
        mdq.insert(arr[i]);
    }
    cout << mdq.get_max() << " ";

    for (int i = k; i < n; i++) {
        mdq.erase(arr[i - k]);
        mdq.insert(arr[i]);
        cout << mdq.get_max() << " ";
    }
    cout << endl;
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
