#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 1e18
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int n, x, y;
int arr[1000100];

// Check function to determine if a subarray of length mid can be made all zeros
bool check(int mid) {
    multiset<int> mt1, mt2;
    int k = mid - y;
    for (int i = 0; i < mid; i++) {
        mt2.insert(arr[i]);
    }
    int cnt = 0;
    int sum = 0;
    for (auto it = mt2.begin(); cnt < k; it++, cnt++) {
        mt1.insert(*it);
        sum += *it;
    }

    for (int i = 0; i < k; i++) {
        mt2.erase(mt2.begin());
    }

    if (sum <= x) {
        return true;
    }

    int l = 0;
    int r = mid;
    while (r < n) {
        // Remove
        if (mt1.count(arr[l])) {
            mt1.erase(mt1.find(arr[l]));
            sum -= arr[l];
            if (!mt2.empty()) {
                auto it = mt2.begin();
                mt1.insert(*it);
                sum += *it;
                mt2.erase(it);
            }
        } else {
            mt2.erase(mt2.find(arr[l]));
        }
        l++;

        // Add
        if (mt1.size() < k) {
            sum += arr[r];
            mt1.insert(arr[r]);
        } else {
            if (arr[r] < *mt1.rbegin()) {
                int rem = *mt1.rbegin();
                sum += arr[r];
                sum -= rem;
                mt1.erase(mt1.find(rem));
                mt1.insert(arr[r]);
                mt2.insert(rem);
            } else {
                mt2.insert(arr[r]);
            }
        }
        r++;

        if (sum <= x) {
            return true;
        }
    }

    return false;
}

void solve() {
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (y >= n) {
        cout << n << endl;
    } else {
        int lo = y;
        int hi = n;
        int ans = y;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << ans << endl;
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
    return 0;
}
