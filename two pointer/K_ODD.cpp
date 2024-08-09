#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> prefix(n);
    prefix[0]=arr[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]+arr[i];
    }
    int oddcnt = 0;
    int head = -1;
    int tail = 0;
    int ans = LLONG_MIN;
    multiset<int> mt;

    while (tail < n) {
        while (head + 1 < n && ((abs(arr[head + 1]) % 2 == 0 || oddcnt < k))) {
            head++;
            if (abs(arr[head]) % 2 == 1) {
                oddcnt++;
            }
            mt.insert(prefix[head]);
        }
        int prefix_tail;
        if(tail==0){
            prefix_tail = 0;
        }else{
            prefix_tail = prefix[tail-1];
        }

        if(!mt.empty()){
            auto it = mt.upper_bound(prefix_tail+d);
            if(it!=mt.begin()){
                it--;
                ans = max(ans,*it-prefix_tail);
            }
        }

        if (head >= tail) {
            if (abs(arr[tail]) % 2 == 1) {
                oddcnt--;
            }
            mt.erase(mt.find(prefix[tail]));
            tail++;
        } else {
            tail++;
            head = tail - 1;
        }
    }

    if (ans == LLONG_MIN) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
