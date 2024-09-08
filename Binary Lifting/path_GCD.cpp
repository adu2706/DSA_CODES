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
vector<int> val;
vector<int> dep;
vector<vector<int>> par,Gcd;

int fun(int a, int b){
    return __gcd(a,b);
}

void dfs(int node, int parent, int depth){
    dep[node] = depth;
    par[node][0] = parent;
    Gcd[node][0] = val[node];

    for(int i=1;i<20;i++){
        par[node][i] = par[par[node][i-1]][i-1];
        Gcd[node][i] = fun(Gcd[node][i-1],Gcd[par[node][i-1]][i-1]);
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

int pathGcd(int u, int v){
    if(dep[u]<dep[v]){
        swap(u,v);
    }

    int ans = 0;
    for(int i=19;i>=0;i--){
        int k = dep[u]-dep[v];
        if(k&(1<<i)){
            ans = fun(ans,Gcd[u][i]);
            u = par[u][i];
        }
    }

    if(u==v){
        return fun(ans,val[u]);
    }

    for(int i=19;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            ans = fun(ans,Gcd[u][i]);
            ans = fun(ans,Gcd[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }

    ans = fun(fun(ans,val[lca(u,v)]),fun(val[u],val[v]));
    return ans;
}

void solve(){
   int n;
   cin>>n; 
   g.resize(n+1);
   val.resize(n+1);
   dep.resize(n+1);
   par = vector<vector<int>>(n+1,vector<int>(20,0));
   Gcd = vector<vector<int>>(n+1,vector<int>(20,0));

   for(int i=1;i<=n;i++){
    cin>>val[i];
   }

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
    int u,v;
    cin>>u>>v;
    cout<<pathGcd(u,v)<<endl;
   }
    g.clear();
    par.clear();
    dep.clear();
    val.clear();
    par.clear();
    Gcd.clear();
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