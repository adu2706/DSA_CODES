#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<int> previous_smaller(int n, vector<int> arr) {
    vector<int> ans(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<int> next_smaller(int n, vector<int> arr) {
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            ans[i] = n;
        } else {
            ans[i] = st.top();
        }
        st.push(i);
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> left = previous_smaller(n, arr);
    vector<int> right = next_smaller(n, arr);

    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int len = right[i] - left[i] - 1;
        if (len > 0) {
            if (mp.find(len) != mp.end()) {
                mp[len] = max(mp[len], arr[i]);
            } else {
                mp[len] = arr[i];
            }
        }
    }

    vector<int> ans(n, 0);
    int len = 1;
    for (auto x : mp) {
        int num = x.second;
        int length = x.first;
        while (len <= length) {
            ans[len - 1] = num;
            len++;
        }
    }

    for(int i=n-2;i>=0;i--){
        if(ans[i]<ans[i+1]){
            ans[i] = ans[i+1];
        }
    }



    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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
