#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;


void solve() {
    int n, q, k;
    cin >> n >> q >> k;

    vector<int> arr(n + 2, 0);
    vector<int> power(n + 2, 1);

    for (int i = 1; i <= n; ++i) {
        power[i] = power[i - 1] * k % mod;
    }

    while (q--) {
        int a, l, r;
        cin >> a >> l >> r;

        arr[l] = (arr[l] + a) % mod;
        if (r + 1 <= n) {
            arr[r + 1] = (arr[r + 1] - a * power[r - l + 1] % mod + mod) % mod;
        }
    }

    for (int i = 1; i <= n; ++i) {
        arr[i] = (arr[i] + arr[i - 1] * k % mod) % mod;
    }

    for (int i = 1; i <= n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
