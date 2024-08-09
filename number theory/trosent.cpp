#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


//prime factor calculation for bigger number like 1e12
vector<int> factorise(int x) {
    vector<int> ans;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            ans.push_back(i);
            while(x % i == 0) {
                x = x / i;
            }
        }
    }
    if(x != 1) {
        ans.push_back(x);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> fact = factorise(n);
    int ans = n;
    for(auto v : fact) {
        ans = ans*(v-1);
        ans = ans/v;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}
