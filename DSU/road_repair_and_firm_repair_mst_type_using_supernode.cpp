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
        sz.assign(x+1,0);
        par.assign(x+1,0);
        for(int i=0;i<=x;i++){
            par[i] = i;
            sz[i] = 1;
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
   int n,m;
   cin>>n>>m;

   vector<int> arr(n+1);
   for(int i=1;i<=n;i++){
    cin>>arr[i];
   }

   vector<pair<int,pair<int,int>>> edges;
   for(int i=0;i<m;i++){
    int a,b,w;
    cin>>a>>b>>w;
    edges.push_back({w,{a,b}});
   }

   for(int i=1;i<=n;i++){
    edges.push_back({arr[i],{0,i}});
   }

   sort(edges.begin(),edges.end());
    DSU dsu;
    dsu.init(n);
    int mst = 0;
   for(auto v:edges){
    int a,b,w;
    w = v.F;
    a = v.S.F;
    b = v.S.S;
    if(dsu.find(a)!=dsu.find(b)){
        mst+=w;
    }
   }

   cout<<mst<<endl;
    
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}