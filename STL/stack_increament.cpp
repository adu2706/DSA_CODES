#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct increment_stack {
    vector<pair<int,int>> st;
    int topCur;

    void init(int maxSize) {
        st.resize(maxSize);
        topCur = 0;
    }

    void push(int x) {
        if(topCur < st.size()) {
            st[topCur].first = x;
            st[topCur].second = 0;
            topCur++;
        }
    }

    int popp() {
        if(topCur != 0) {
            topCur--;
            st[topCur].first += st[topCur].second;
            if(topCur) {
                st[topCur-1].second += st[topCur].second;
            }
            return st[topCur].first;
        }
        return -1;
    }

    void increment(int k, int val) { 
        k = min(k, topCur);
        k--;
        if(k >= 0) {
            st[k].second += val;
        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    increment_stack is;
    is.init(n);

    while(q--) {
        string s;
        cin >> s;
        if(s == "push") {
            int x;
            cin >> x;
            is.push(x);
        } else if(s == "pop") {
            cout << is.popp() << endl;  
        } else {
            int k, val;
            cin >> k >> val;
            is.increment(k, val);  
        }
    }
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
