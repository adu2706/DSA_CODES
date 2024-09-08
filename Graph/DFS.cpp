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
int num_node;
void dfs(int node, int color){
    vis[node] = color;
    num_node++;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,color);
        }
    }
}
void solve(){
   int n,m;
   cin>>n>>m;
   g.resize(n+1);
   vis.assign(n+1,0);
   for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    //undirected
    g[b].push_back(a);
   }

   int color = 0;
   vector<int> num_comp;//storing number component
   for(int i=1;i<=n;i++){
    if(!vis[i]){
        color++;
        num_node=0;
        dfs(i,color);
        num_comp.push_back(num_node);
    }
   }

   int total_number_of_connected_component = color;

   int q;
   cin>>q;
   while(q--){
    int a,b;
    cin>>a>>b;
    //check a and b are connected to same component are not;
    if(vis[a]==vis[b]){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
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