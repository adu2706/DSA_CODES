#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

void solve(){
    int n, X;
    cin >> n >> X;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(arr.begin()+i+1, arr.end(), X - arr[i]) - arr.begin();
        it--;
        ans += (it - i);
    }
    cout << ans*2 << endl;
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
}
