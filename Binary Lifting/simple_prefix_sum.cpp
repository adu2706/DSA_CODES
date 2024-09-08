#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<vector<pair<int,int>>> g;
vector<int> dep;
vector<vector<int>> par;
vector<int> prefix;

void dfs(int node, int parent, int depth, int val){
    prefix[node] = prefix[parent]+val;
    dep[node] = depth;
    par[node][0] = parent;

    for(int i=1;i<20;i++){
        par[node][i] = par[par[node][i-1]][i-1];
    }

    for(auto v:g[node]){
        if(v.first!=parent){
            dfs(v.first,node,depth+1,v.second);
        }
    }
}



int lca(int u,int v){
    if(dep[u]<dep[v]){
        swap(u,v);
    }

    for(int i=19;i>=0;i--){
        if((dep[u]-dep[v])&(1<<i)){
            u = par[u][i];
        }
    }

    if(u==v){
        return u;
    }

    for(int i=19;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }

    return par[u][0];
}

void solve(){
    int n;
    cin>>n;
    g.resize(n+1);
    par = vector<vector<int>> (n+1,vector<int>(20,0));
    dep.resize(n+1);
    prefix.assign(n+1,0);

    for(int i=0;i<n-1;i++){
        int a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }

    dfs(1,0,0,0);
    
    int q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<prefix[u]+prefix[v]-2*prefix[lca(u,v)]<<endl;
    }

    g.clear();
    par.clear();
    prefix.clear();
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