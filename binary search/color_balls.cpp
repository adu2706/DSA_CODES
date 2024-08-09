#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int n, k;
vector<int> arr;
map<int, int> mp;

bool check(int mid) {
    int tempk = 0;
    int sum = 0;
    for (auto v : mp) {
        if (v.second >= mid) {
            tempk++;
        } else {
            sum += v.second;
        }
    }
    tempk += sum / mid;
    return tempk >= k;
}

void solve() {
    cin >> n >> k;
    arr.resize(n);
    mp.clear(); 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }
    int lo = 1;  
    int hi = n;  
    int ans = 0;
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
