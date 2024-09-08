#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct DSU{
    vector<int> sz;
    vector<int> par;
    int set_size;
    int n;

    void init(int x){
        set_size = x;
        n = x;
        sz.assign(x+1,1);
        par.assign(x+1,0);
        for(int i=1;i<=x;i++){
            par[i] = i;
        }
    }

    int find(int x){
        if(par[x]==x){
            return x;
        }
        return par[x] = find(par[x]);
    }

    void merge(int x, int y){
        int xroot = find(x);
        int yroot = find(y);
        if(xroot!=yroot){
            if(sz[xroot]<sz[yroot]){
                swap(xroot,yroot);
            }

            par[yroot] = xroot;
            sz[xroot] += sz[yroot];
            set_size--;
        }
    }

    int st_size(){
        return set_size;
    }
};

void solve(){
   int n,m,q;
   cin>>n>>m>>q;

    DSU dsu;
    dsu.init(n);
    
    vector<pair<int,int>> edge(m);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edge[i] = {a,b};
    }

    vector<pair<int,int>> query(q);
    vector<int> marked(m+1, 0);
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        if(x==1){
            int y;
            cin>>y;
            query[i] = {x,y};
            marked[y] = 1;
        } else {
            query[i] = {x,0};
        }
    }

    for(int i=1;i<=m;i++){
        if(!marked[i]){
            dsu.merge(edge[i-1].F, edge[i-1].S);
        }
    }
    
    vector<int> ans;
    for(int i=q-1;i>=0;i--){
        int x = query[i].F;
        int y = query[i].S;
        if(x==1){
            dsu.merge(edge[y-1].F, edge[y-1].S);
        } else {
            ans.push_back(dsu.st_size());
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto v:ans){
        cout<<v<<endl;
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
