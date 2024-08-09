#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

void solve() {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        ans += ((int)(log2(l)/log2(3)) + 1)+((int)(log2(l)/log2(3)) + 1);
        
        while(l<r){
            ans += (((int)(log2(r)/log2(3)) + 1)*(1+r - max((int)pow(3,(int)(log2(r)/log2(3))),l+1)));
            r = (int)pow(3,(int)(log2(r)/log2(3))) - 1;
        }
        
        cout << ans << endl;
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
