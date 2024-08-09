#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct range_maintainance {
    set<pair<int,int>> ranges;

    void fill_range(int l, int r) {
        auto it = ranges.upper_bound({l, 1e18});
        if(it != ranges.begin()) {
            it--;
            if(it->second >= l) {
                l = it->first;
                r = max(r, it->second);  
                ranges.erase(it);
            }
        }
        
        it = ranges.upper_bound({r, 1e18});
        if(it != ranges.begin()) {
            it--;
            if(it->second >= r) {
                r = it->second;
                l = min(l, it->first);  
                ranges.erase(it);
            }
        }

        while(1) {
            it = ranges.lower_bound({l, 0});
            if(it == ranges.end() || it->first > r) {
                break;
            } else {
                ranges.erase(it);
            }
        }

        ranges.insert({l, r});
    }

    void clear_range(int l, int r) {
        auto it = ranges.upper_bound({l, 1e18});
        if(it != ranges.begin()) {
            it--;
            if(it->second >= r) {
                int lo1 = it->first;
                int hi1 = l;

                int lo2 = r;
                int hi2 = it->second;
                ranges.erase(it);
                ranges.insert({lo1, hi1});
                ranges.insert({lo2, hi2});
                return;
            }
            if(it->second >= l) {
                int lo = it->first;
                int hi = l;
                ranges.erase(it);
                ranges.insert({lo, hi});
            }
        }

        it = ranges.upper_bound({r, 1e18});
        if(it != ranges.begin()) {
            it--;
            if(it->second > r) {
                int lo = r;
                int hi = it->second;
                ranges.erase(it);
                ranges.insert({lo, hi});
            }
        }

        while(1) {
            it = ranges.lower_bound({l, 0});
            if(it == ranges.end() || it->first >= r) {
                break;
            } else {
                ranges.erase(it);
            }
        }
    }

    bool check_point(int x) {
        auto it = ranges.upper_bound({x, 1e18});
        if(it == ranges.begin()) {
            return false;
        } else {
            it--;
            if(it->second >= x) {
                return true;
            } else {
                return false;
            }
        }
    }

    bool check_range_any(int x, int y) {
        auto it = ranges.upper_bound({x, 1e18});
        if(it != ranges.begin()) {
            it--;
            if(it->second >= x) {
                if(it->second >= y || it->first <= y) {
                    return true;
                }
            }
        }
        return check_point(x) || check_point(y);
    }

    bool check_range_all(int x, int y) {
        auto it = ranges.upper_bound({x, 1e18});
        if(it == ranges.begin()) {
            return false;
        } else {
            it--;
            if(it->first <= x && it->second >= y) {
                return true;
            } else {
                return false;
            }
        }
    }

    void print_status() {
        for(auto v: ranges) {
            cout << '(' << v.F << ',' << v.S << "), ";
        }
        cout << endl;
    }
};

void solve() {
    int q;
    cin >> q;
    range_maintainance rm;
    while(q--) {
        int ch;
        cin >> ch;
        if(ch == 1) {
            int l, r;
            cin >> l >> r;
            rm.fill_range(l, r);
        } else if(ch == 2) {
            int l, r;
            cin >> l >> r;
            rm.clear_range(l, r);
        } else if(ch == 3) {
            int x;
            cin >> x;
            cout << rm.check_point(x) << endl;
        } else if(ch == 4) {
            int x, y;
            cin >> x >> y;
            cout << rm.check_range_any(x, y) << endl;
        } else if(ch == 5) {
            int x, y;
            cin >> x >> y;
            cout << rm.check_range_all(x, y) << endl;
        }

        rm.print_status();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}
