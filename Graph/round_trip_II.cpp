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
bool is_cycle;

void dfs(int node){
    vis[node] = 2;

    for(auto v:g[node]){
        if(vis[v]==1){
            dfs(v);
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
   g.clear();
   vis.clear();
   g.resize(n+1);
   vis.assign(n+1,1);
   for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    if(a!=b){
        g[a].push_back(b);
    }
    
   }

    is_cycle=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==1){
            dfs(i);
        }
    }
   
   if(is_cycle){
    cout<<"Yes"<<endl;
   }else{
    cout<<"No"<<endl;
   }
    
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