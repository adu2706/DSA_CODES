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
vector<int> vis;
vector<int> par;
bool is_cycle;

void dfs(int node, int parent){
    vis[node] = 2;
    par[node] = parent;

    for(auto v:g[node]){
        if(v==par[node]){
            continue;
        }
        if(vis[v]==1){
            dfs(v,node);
        }else if(vis[v]==2){
            is_cycle=1;
            break;
        }
    }
    vis[node] = 3;
}

void solve(){
   int n,m;
   cin>>n>>m;
   g.resize(n+1);
   vis.assign(n+1,1);
   par.assign(n+1,0);
   map<pair<int,int>,int> edgecnt;
   for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    if(a==b){
        //self loop
    }
    if(a>b){
        swap(a,b);
    }
    edgecnt[{a,b}]++;
    if(edgecnt[{a,b}]>1){
        //multiedge
    }else{
        g[a].push_back(b);
        g[b].push_back(a);
    }
   }

    is_cycle=0;
    for(int i=1;i<=n;i++){
        if(is_cycle==0 && vis[i]==1){
            dfs(i,0);
        }
    }
   
   if(is_cycle){
    cout<<"YES"<<endl;
   }else{
    cout<<"NO"<<endl;
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