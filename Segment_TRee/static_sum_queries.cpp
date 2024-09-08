#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct Node{
    vector<int> v;
    Node(){
        v.clear();
    }
};


struct segTree{
    vector<int> tree;
    vector<int> arr;
    void declaring(int n, vector<int> a){
        tree.resize(4*n + 400);
        arr = a;
    }

    void build(int index, int l, int r){
        if(l==r){
            tree[index] = arr[l];
            return;
        }

        int mid = (l+r)/2;
        
        build(2*index,l,mid);
        build(2*index+1,mid+1,r);
        tree[index] = tree[2*index] + tree[2*index+1];
    }

    void update(int index, int l, int r, int pos, int val){
        if(pos<l || pos>r){
            return;
        }

        if(l==r){
            tree[index] = val;
            arr[l] = val;
            return;
        }

        int mid = (l+r)/2;
        
        update(2*index,l,mid,pos,val);
        update(2*index+1,mid+1,r,pos,val);
        tree[index] = tree[2*index] + tree[2*index+1];
    }

    int query(int index, int l, int r, int st, int en){
        if(en<l || st>r){
            return 0;
        }

        if(st<=l && r<=en){
            return tree[index];
        }

        int mid = (l+r)/2;

        return query(2*index,l,mid,st,en)+query(2*index+1,mid+1,r,st,en);
    }
};


void solve(){
   int n,q;
   cin>>n>>q;
   vector<int>a(n);
   for(int i=0;i<n;i++){
    cin>>a[i];
   }

   segTree st;
   st.declaring(n,a);
   st.build(1,0,n-1);
    while(q--){
        int s,e;
        cin>>s>>e;
        s--,e--;
        cout<<st.query(1,0,n-1,s,e)<<endl;
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