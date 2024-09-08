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
void dfs(int node, int color){
    vis[node] = color;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,color);
        }
    }
}
void solve(){
   int n,m,q;
   cin>>n>>m>>q;

   g.clear();
   g.resize(n+1);
   vis.assign(n+1,0);
   for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
   }

   int color = 0;
   vector<vector<int>>comp;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            color++;
            dfs(i,color);
        }
    }
    comp.resize(color+1);
    for(int i=1;i<=n;i++){
        comp[vis[i]].push_back(i);
    }

    while(q--){
        int ch;
        cin>>ch;
        if(ch==1){
            int x;
            cin>>x;
            cout<<comp[vis[x]].size()<<endl;
        }else{
            int x,y;
            cin>>x>>y;
            if(vis[x]==vis[y]){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
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