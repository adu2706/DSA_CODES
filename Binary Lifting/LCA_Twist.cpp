#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define end '/n'
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


vector<vector<int>> g;
vector<vector<int>> par;
vector<int> dep;

void dfs(int node, int parent, int depth){
    par[node][0] = parent;
    dep[node] = depth;

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
        int dis = dep[u]-dep[v];
        if(dis&(1<<i)){
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
    return  par[u][0];
}


void solve(){
   int n;
   cin>>n;
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

   int q;
   cin>>q;
   while(q--){
    int u,v,z;
    cin>>u>>v>>z;
    int i = lca(u,v);
    int a = lca(u,z);
    int b = lca(v,z);

    if(i==a || i==b){
        //z must be lies in u branch node or v branched node
        if(i==a){
            //z lies in v branch node
            //so lca of u and v when z is root is lca(v,z)==b
            cout<<b<<endl;
        }else if(i==b){
            //z lies in u branch node
            //so lca of u and v when z is root is lca(u,z)==a
            cout<<a<<endl;
        }
    }else{
        // z neither lie in v branch node or u branch node
        // lca(u,v) when z is rooted is (lca(u,v)==i) for the past rooted tree which rooted at 1
        cout<<i<<endl;
    }
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
    cin>>t;
    while(t--){
        solve();
    }
}