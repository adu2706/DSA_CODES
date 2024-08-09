#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
const int MOD = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    set<int> st;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        st.insert(arr[i]);
    }

    int m = st.size();
    int head = -1;
    int tail = 0;
    int ans = n;
    vector<int> freq(100010, 0);
    int distCnt = 0;

    while(tail < n) {
        while(head + 1 < n && distCnt < m) {
            head++;
            if(freq[arr[head]] == 0) {
                distCnt++;
            }
            freq[arr[head]]++;
        }
        if(distCnt==m){
            ans = min(ans, head - tail + 1);
        }

        if(head >= tail) {
            freq[arr[tail]]--;
            if(freq[arr[tail]] == 0) {
                distCnt--;
            }
            tail++;
        } else {
            tail++;
            head = tail - 1;
        }
    }

    cout << ans << endl;
}

int32_t main() {
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
