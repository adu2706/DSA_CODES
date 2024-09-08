#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<vector<int>> g;
vector<vector<int>> par;
vector<int> dep;

//prep-processing
void dfs(int node, int parent, int depth){
    par[node][0] = parent;
    dep[node] = depth;

    for(int i=1;i<20;i++){
        //next(x,i) == x + 2^i
        // next(x,i) = next(next(x,i-1),i-1)    { ((x+2^(i-1))+2^(i-1)) == x+(2^(i-1)+2^(i-1)) == x+2^i }
        par[node][i] = par[par[node][i-1]][i-1];
    }

    for(auto v:g[node]){
        if(v!=parent){
            dfs(v,node,depth+1);
        }
    }
}


//query step1 
int lca(int u, int v){
    if(dep[u]<dep[v]){
        //v always above or on equal level to u (only just for smplicity)
        swap(u,v);
    }
    
    for(int i=19;i>=0;i--){
        int k = dep[u]-dep[v];
        if(k&(1<<i)){
            u = par[u][i];
        }
    }

    if(u==v){
        return u;
    }

    for(int i=19;i>=0;i--){
        if(par[v][i]!=par[u][i]){
            v = par[v][i];
            u = par[u][i];
        }
    }

    return par[u][0];
}


void solve(){
    int n,q;
    cin>>n>>q;
    g.resize(n+1);
    par = vector<vector<int>>(n+1,vector<int>(20,0));
    dep.resize(n+1);
    for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
    }
    dfs(1,0,0);
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
    g.clear();
    par.clear();
    dep.clear();
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