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
        for(int i=1;i<=x;i++){
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
   int n;
   cin>>n;

    DSU dsu;
    dsu.init(n);

    int q;
    cin>>q;
    vector<int> ans;
    vector<pair<int,int>> query;
    while (q--){
        int a,b;
        cin>>a>>b;
        query.push_back({a,b});
    }
    reverse(query.begin(),query.end());

    for(auto v:query){
        int a = v.first;
        int b = v.second;
        ans.push_back(dsu.st_size());
        dsu.merge(a,b);
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