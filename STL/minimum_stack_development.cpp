#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 1e9
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct min_stack {
    int minElement;
    stack<int> st;

    min_stack() {
        minElement = INF;
    }

    void push(int x) {
        if (st.empty()) {
            st.push(x);
            minElement = x;
        } else {
            if (x >= minElement) {
                st.push(x);
            } else {
                int y = 2*x - minElement;
                st.push(y);
                minElement = x;
            }
        }
    }

    void pop() {
        if (st.empty()) {
            return;
        }
        int y = st.top();
        st.pop();
        if (y < minElement) {
            minElement = 2*minElement - y;
        }
    }

    int get_min() {
        if (st.empty()) {
            return INF; 
        }
        return minElement;
    }
};

void solve() {
    int q;
    cin >> q;
    min_stack ms;

    while (q--) {
        string s;
        cin >> s;
        if (s == "getMin") {
            cout << ms.get_min() << endl;
        } else if (s == "pop") {
            ms.pop();
        } else if (s == "push") {
            int x;
            cin >> x;
            ms.push(x);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
