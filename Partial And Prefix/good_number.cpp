#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1000000;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    
    vector<int> likes(MAX + 2, 0);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        likes[l]++;
        if (r + 1 <= MAX) {
            likes[r + 1]--;
        }
    }

    for (int i = 1; i <= MAX; i++) {
        likes[i] += likes[i - 1];
    }

    vector<int> good(MAX + 1, 0);
    for (int i = 1; i <= MAX; i++) {
        good[i] = good[i - 1] + (likes[i] >= k ? 1 : 0);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << good[r] - good[l - 1] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
