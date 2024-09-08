#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<vector<int>> g,par;
vector<int> dep;
vector<int> val;

void dfs(int node, int parent, int depth){
    dep[node] = depth;
    par[node][0] = parent;

    for(int i=1;i<20;i++){
        par[node][i] = par[par[node][i-1]][i-1];
    }

    for(auto v:g[node]){
        if(v!=parent){
            dfs(v,node,depth+1);
        }
    }
}

int lca(int u, int v){
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

void dfs2(int node, int par){
    for(auto v:g[node]){
        if(v!=par){
            dfs2(v,node);
        }
    }

    val[par] += val[node];
}

void solve(){
   int n;
   cin>>n;
   g.resize(n+1);
   par = vector<vector<int>> (n+1,vector<int>(20,0));
   dep.resize(n+1);
   val.resize(n+1,0);

   for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
   }
    dfs(1,0,0);
   int q;
   cin>>q;
   while(q--){
    int u,v,x;
    cin>>u>>v>>x;
    val[u]+=x;
    val[v]+=x;
    val[lca(u,v)]-=x;
    val[par[lca(u,v)][0]]-=x;
   }
   dfs2(1,0);
    for(int i=1;i<=n;i++){
        cout<<val[i]<<" ";
    }
    cout<<endl;
    g.clear();
    par.clear();
    val.clear();
    dep.clear();
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