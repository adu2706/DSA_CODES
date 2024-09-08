#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
#define endl '\n'
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<vector<int>> g;
vector<int> vis,par;
vector<int> col;
int n,m;

int is_possible;
void dfs(int node, int parent,int color){
    if(is_possible==0){
        return;
    }
    vis[node] = 1;
    par[node] = parent;
    col[node] = color;

    for(auto v:g[node]){
        if(v==par[node]){
            continue;
        }

        if(vis[v]==0){
            dfs(v,node,color^3);
        }else if(vis[v]){
            if(col[v]==col[node]){
                is_possible=0;
            }
        }
    }
}
void solve(){
   cin>>n>>m;
   g.resize(n+1);
   par.assign(n+1,0);
   vis.assign(n+1,0);
   col.assign(n+1,0);
   for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
   }

   is_possible=1;

   for(int i=1;i<=n;i++){
    if(is_possible==0){
        break;
    }else if(is_possible==1 && vis[i]==0){
        dfs(i,0,1);
    }
   }

   if(is_possible){
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