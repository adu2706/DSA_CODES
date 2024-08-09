#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<int> prefix_greater(int n, vector<int>& arr) {
    vector<int> ans(n);
    ans[0] = arr[0];
    for(int i = 1; i < n; i++) { 
       ans[i] = max(ans[i-1], arr[i]);
    }
    return ans;
}

vector<int> suffix_greater(int n, vector<int>& arr) {
    vector<int> ans(n);
    ans[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--) {
       ans[i] = max(ans[i+1], arr[i]);
    }
    return ans;
}

void solve() { 
   int n;
   cin >> n;
   vector<int> arr(n);
   for(int i = 0; i < n; i++) {
       cin >> arr[i];
   }

   vector<int> left = prefix_greater(n, arr);
   vector<int> right = suffix_greater(n, arr);

   int ans = 0;
   for(int i = 0; i < n; i++) {
        ans += min(left[i], right[i]) - arr[i];
   }
   cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
