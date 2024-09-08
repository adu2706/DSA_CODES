#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct segTree{
    vector<int> t;
    vector<int> arr;

    void declare(int n, vector<int> a){
        t.resize(4*n + 400);
        arr = a;
    }

    void build(int index, int l, int r){
        if(l == r){
            t[index] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(2*index, l, mid);
        build(2*index+1, mid+1, r);

        t[index] = t[2*index] + t[2*index+1];
    }

    void update(int index, int l, int r, int kth){
        if(l == r){
            t[index] = 0;
            return;
        }

        int mid = (l + r) / 2;

        if(kth <= t[2*index]){
            update(2*index, l, mid, kth);
        } else {
            update(2*index+1, mid+1, r, kth - t[2*index]);
        }
        
        t[index] = t[2*index] + t[2*index+1];
    }

    int query(int index, int l, int r, int kth){
        if(l == r){
            return arr[l];
        }

        int mid = (l + r) / 2;

        if(kth <= t[2*index]){
            return query(2*index, l, mid, kth);
        } else {
            return query(2*index+1, mid+1, r, kth - t[2*index]);
        }
    }
};

void solve(){
   int n;
   cin >> n;
   vector<int> arr(n);

   for(int i = 0; i < n; i++){
       cin >> arr[i];
   }

   segTree st;
   st.declare(n, arr);
   st.build(1, 0, n-1);

   int q = n;

   while(q--){
       int x;
       cin >> x;

       cout << st.query(1, 0, n-1, x) << " ";
       st.update(1, 0, n-1, x);
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
