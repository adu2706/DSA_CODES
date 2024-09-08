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
        t.resize(4*n+400);
    }

    void build(int index, int l, int r){
        if(l==r){
            t[index] = 0;
            return;
        }

        int mid = (l+r)/2;
        
        build(2*index,l,mid);
        build(2*index+1,mid+1,r);

        t[index] = t[2*index]+t[2*index+1];
    }

    void update(int index, int l, int r, int pos){
        if(pos<l || pos>r){
            return;
        }

        if(l==r){
            t[index] = t[index]^1;
            return;
        }

        int mid = (l+r)/2;
        
        update(2*index,l,mid,pos);
        update(2*index+1,mid+1,r,pos);

        t[index] = t[2*index]+t[2*index+1];
    }

    int query(int index, int l, int r, int pos){
        if(pos<l){
            return 0;
        }
        if(pos>=r){
            return t[index];
        }

        int mid = (l+r)/2;

        return query(2*index,l,mid,pos)+query(2*index+1,mid+1,r,pos);
    }
};


void solve(){
   int n,q;
   cin>>n>>q;
   segTree st;
   st.declare(n);
   st.build(1,0,n-1);

   map<int,int> mp;
   int i=0;
   vector<pair<int,int>> v;
   vector<int> temp;
   while(q--){
    int ch,x;
    cin>>ch>>x;
    v.push_back({ch,x});
    temp.push_back(x);
   }

   sort(temp.begin(),temp.end());

   for(auto x:temp){
    if(mp.find(x)==mp.end()){
        mp[x]=i;
        i++;
    }
   }


   for(auto x:v){
    int ch = x.first;
    int val = mp[x.second];
    if(ch==1){
        st.update(1,0,n-1,val);
    }else{
        cout<<st.query(1,0,n-1,val)<<endl;
    }
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