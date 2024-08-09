#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int n,s;

int sum_of_digits(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}


bool check(int mid, int s) {
    int sum_digits = sum_of_digits(mid);
    return (mid - sum_digits >= s);
}

void solve(){
    cin >> n >> s;
    int lo = 1;
    int hi = n;
    int ans = n + 1;  
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid, s)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    int finalans = (ans <= n) ? (n - ans + 1) : 0; 
    cout << finalans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
