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
vector<int> any_cycle;
vector<int> cnt_cycle;
vector<int> prefix_order;
bool cycle;

void dfs(int node, int parent){
    vis[node] = 2;
    par[node] = parent;
    for(auto v:g[node]){
        if(vis[v]==1){
            //this is forward edge
            dfs(v,node);
        }else if(vis[v]==2){
            //this is back edge
            //we found a cycle
            if(cycle==false){
                int temp = node;
                while(temp!=v){
                    any_cycle.push_back(temp);
                    temp = par[temp];
                }
                any_cycle.push_back(temp);
            }
            cnt_cycle[node]++;
            cnt_cycle[par[v]]--;
            cycle=true;

        }else if(vis[v]==3){
            //this is cross edge
            //not important
        }
    }
    
    vis[node]=3;
    prefix_order.push_back(node);
}

void solve(){
   int n,m;
   cin>>n>>m;
   g.resize(n+1);
   par.assign(n+1,0);
   vis.assign(n+1,1);
   cnt_cycle.assign(n+1,0);

   for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    //directed graph
    g[a].push_back(b);
   }
    
   cycle = false;
   for(int i=1;i<=n;i++){
    if(vis[i]==1){
        dfs(i,0);
    }
   }

   reverse(any_cycle.begin(),any_cycle.end());

   for(auto v:any_cycle){
    cout<<v<<" ";
   }
    cout<<endl;
   for(auto v:prefix_order){
    cnt_cycle[par[v]]+=cnt_cycle[v];
   }

   int cntnode = 0;
   for(int i=1;i<=n;i++){
    //counting all nodes that are part of some cycle 
    if(cnt_cycle[i]>0){
        cntnode++; 
    }
   }
   cout<<cntnode<<endl;

   

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