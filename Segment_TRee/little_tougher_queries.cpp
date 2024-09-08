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
    vector<int> a;
};

struct segTree{
    vector<node> tree;
    vector<int> arr;

    void declare(int n, vector<int> a){
        tree.resize(4*n+400);
        arr = a;
    }

    void build(int index, int l, int r){
        for(int i=l;i<=r;i++){
            tree[index].a.push_back(arr[i]);
        }
        sort(tree[index].a.begin(),tree[index].a.end());

        if(l==r){
            return;
        }

        int mid = (l+r)/2;
        build(2*index,l,mid);
        build(2*index+1,mid+1,r);
    }

    int query(int index, int l, int r, int st, int en, int val){
        if(st>r || en<l){
            return 0;
        }

        if(st<=l && r<=en){
            auto it = upper_bound(tree[index].a.begin(),tree[index].a.end(),val)-tree[index].a.begin();
            return it;
        }
        
        int mid = (l+r)/2;
        return query(2*index,l,mid,st,en,val)+query(2*index+1,mid+1,r,st,en,val);
    }
};


void solve(){
   int n,q;
   cin>>n>>q;
   vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    segTree st;
    st.declare(n,arr);
    st.build(1,0,n-1);
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        l--,r--;
        int left = 1;
        int right = 1e9+10;
        int ans = 0;
        while(left<=right){
            int mid = (left+right)/2;
            if(st.query(1,0,n-1,l,r,mid)>=k){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        cout<<ans<<endl;
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}