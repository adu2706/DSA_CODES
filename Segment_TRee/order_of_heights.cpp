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
    void declare(int n){
        t.resize(4*n + 400);
    }

    void build(int index, int l, int r){
        if(l == r){
            t[index] = 1;  // Initialize with 1 as there's one element in this segment
            return;
        }

        int mid = (l + r) / 2;

        build(2*index, l, mid);
        build(2*index+1, mid+1, r);

        t[index] = t[2*index] + t[2*index+1];
    }

    void update(int index, int l, int r, int kth){
        if(l == r){
            t[index] = 0;  // Mark this element as removed
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
            return l;  // Found the kth element
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
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x] = i;  // Mapping the value to its index
    }

    segTree st;
    st.declare(n);
    st.build(1, 0, n - 1);
    
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    vector<int> ans(n);
    
    for(auto v : mp){
        int h = v.first;
        int idx = v.second;

        int pos = st.query(1, 0, n-1, p[idx] + 1);  // Find the position for this value
        ans[pos] = idx+1;  // Place the original value
        st.update(1, 0, n-1, p[idx] + 1);  // Update the tree to remove this position
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";  // Print the result
    }
    cout << endl;
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
