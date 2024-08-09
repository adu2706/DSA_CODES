#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<vector<int>> p(n, vector<int>(31, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 30; j++) {
                p[i][j] = ((a[i] >> j) & 1);
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= 30; j++) {
                p[i][j] += p[i - 1][j];
            }
        }

        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; r--; 
            int x1 = 0, x2 = 0, x3 = 0;
            for (int i = 0; i <= 30; i++) {
                int co = p[r][i] - (l > 0 ? p[l - 1][i] : 0);
                int cz = (r - l + 1) - co;
                if (co < cz) {
                    x1 += (1LL << i);
                }
                if (co != (r - l + 1)) x2 += (1LL << i);
                if (co > 0) x3 += (1LL << i);
            }
            cout << x1 + x2 + x3 << endl;
        }
    }

    return 0;
}