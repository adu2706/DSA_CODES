#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int n,m;
vector<vector<int>> g;
vector<int> vis,tin,low;
vector<int> extra;
vector<pair<int,int>> bridges;
int total,timer;

void dfs(int node, int parent){
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;
    vector<int> childnodes;
    for(auto v:g[node]){
        if(v==parent){
            continue;
        }

        if(vis[v]){
            //back edges
            low[node] = min(low[node],tin[v]);
        }else{
            childnodes.push_back(v);
            dfs(v,node);
            //forward edges
            low[node] = min(low[node],low[v]);
            child++;
        }
    }

    if(parent==0){
        //root node
        extra[node] = child-1;
        // for(auto v:childnodes){
        //     //bridges
        //     if(low[v]>tin[node]){
        //         bridges.push_back({node,v});
        //     }
        // }
    }else{
        //mid nodes
        for(auto v:childnodes){
            if(low[v]>=tin[node]){
                extra[node]++;
            }
            // if(low[v]>tin[node]){
            //     //bridges
            //     bridges.push_back({node,v});
            // }
        }
    }
}

void solve(){
   cin>>n>>m;
   g.resize(n+1);
   for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
   }
   extra.resize(n+1,0);
   vis.assign(n+1,0);
   tin.assign(n+1,0);
   low.assign(n+1,0);

   timer = 1;
   total = 0;

   for(int i=1;i<=n;i++){
    if(!vis[i]){
        total++;
        dfs(i,0);
    }
   }

   cout<<"total component initial : "<<total<<endl;

   for(int i=1;i<=n;i++){
    cout<<i<<" : "<<total+extra[i]<<endl;
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