#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct node{
    pair<int,int> p;
};

struct segtree{
    vector<node> t;
    vector<int> arr;

    void declare(int n, vector<int> a){
        arr = a;
        t.resize(4*n + 400);
    }

    pair<int,int> merge(pair<int,int> x, pair<int,int> y){
        return {x.first + y.first, x.second + y.second};
    }

    void build(int index, int l, int r){
        if(l == r){
            if(arr[l] % 2 == 0){
                t[index].p = {1, 0};
            }else{
                t[index].p = {0, 1};
            }
            return; 
        }
        int mid = (l + r) / 2;
        build(2 * index, l, mid);
        build(2 * index + 1, mid + 1, r);
        t[index].p = merge(t[2 * index].p, t[2 * index + 1].p);
    }

    void update(int index, int l, int r, int pos, int val){
        if(pos < l || pos > r){
            return;
        }

        if(l == r){
            if(val % 2 == 0){
                t[index].p = {1, 0};
            }else{
                t[index].p = {0, 1};
            }
            return;
        }

        int mid = (l + r) / 2;
        update(2 * index, l, mid, pos, val);
        update(2 * index + 1, mid + 1, r, pos, val);
        t[index].p = merge(t[2 * index].p, t[2 * index + 1].p);
    }

    int query(int index, int l, int r, int st, int en, int type){
        if(en < l || st > r){
            return 0;
        }

        if(st <= l && r <= en){
            if(type == 1){
                return t[index].p.first;
            }else{
                return t[index].p.second;
            }
        }

        int mid = (l + r) / 2;
        return query(2 * index, l, mid, st, en, type) + query(2 * index + 1, mid + 1, r, st, en, type);
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    segtree sg;
    sg.declare(n, arr);
    sg.build(1, 0, n - 1);
    int q;
    cin>>q;
    while(q--){
        int ch;
        cin >> ch;
        if(ch == 0){
            // Update
            int pos, val;
            cin >> pos >> val;
            pos--;
            sg.update(1, 0, n - 1, pos, val);
        }else if(ch == 1){
            // Query type 1
            int l, r;
            cin >> l >> r;
            l--, r--;
            auto ans = sg.query(1, 0, n - 1, l, r, 1);
            cout << ans << endl;
        }else{
            // Query type 2
            int l, r;
            cin >> l >> r;
            l--, r--;
            auto ans = sg.query(1, 0, n - 1, l, r, 2);
            cout << ans << endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
