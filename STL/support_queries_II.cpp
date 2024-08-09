#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


struct bag {
    int sumK;
    int K;
    multiset<int> lo, hi;

    void init(int _K) {
        sumK = 0;
        K = _K;
        lo.clear();
        hi.clear();
    }

    void insert(int x) {
        hi.insert(x);
        sumK += x;
        if (hi.size() > K) {
            auto it = hi.begin();   
            sumK -= *it;
            lo.insert(*it);
            hi.erase(it);
        }
    }

    void remove(int x) {
        if (hi.find(x) != hi.end()) {
            sumK -= x;
            hi.erase(hi.find(x));
            if (!lo.empty()) {
                auto it = lo.end();
                it--;
                sumK += *it;
                hi.insert(*it);
                lo.erase(it);
            }
        } else if (lo.find(x) != lo.end()) {
            lo.erase(lo.find(x));
        }
    }

    int get_sumK() {
        return sumK;
    }
};

void solve() {
    int q, k;
    cin >> q >> k;
    bag bg;
    bg.init(k);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int val;
            cin >> val;
            bg.insert(val);
        } else if (type == 2) {
            int val;
            cin >> val;
            bg.remove(val);
        } else if (type == 3) {
            string s;
            cin >> s;
            cout << bg.get_sumK() << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
