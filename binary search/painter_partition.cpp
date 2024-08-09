#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define int long long
#define F first
#define S second

const int MOD = 1e9 + 7;

typedef pair<int, int> pii;

int n, k;
vector<int> arr;

bool check(int sum) {
    int remainingK = k-1;
    int currentSum = sum;
    for (int i = 0; i < n; i++) {
        if (sum < arr[i]) {
            return false;
        }
        if (currentSum >= arr[i]) {
            currentSum -= arr[i];
        } else {
            remainingK--;
            currentSum = sum - arr[i];
            if (remainingK < 0) {
                return false;
            }
        }
    }
    return remainingK >= 0;
}

void solve() {
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int lo = 0;
    int hi = 1e18;
    int ans = 1e18;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
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
    return 0;
}
