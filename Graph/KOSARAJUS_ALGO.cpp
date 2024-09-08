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
vector<vector<int>>  condensed_g;
vector<vector<int>> g,reverse_g;
vector<int> vis;

vector<int> tout_order;

void dfs1(int node){
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs1(v);
        }
    }
    tout_order.push_back(node);
}


vector<int> scc_num;
void dfs2(int node, int cur_scc){
    scc_num[node] = cur_scc;
    vis[node] = 1;
    for(auto v:reverse_g[node]){
        if(!vis[v]){
            dfs2(v,cur_scc);
        }
    }
}

void solve(){
   cin>>n>>m;
   g.resize(n+1);
   reverse_g.resize(n+1);

   for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    reverse_g[b].push_back(a);
   }
    vis.assign(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs1(i);
        }
    }

    reverse(tout_order.begin(),tout_order.end());

    vis.assign(n+1,0);
    scc_num.assign(n+1,0);
    int cur_scc = 0;
    for(auto v:tout_order){
        if(!vis[v]){
            cur_scc++;
            dfs2(v,cur_scc);
        }
    }
    cout<<"total strongly connected component : "<<cur_scc<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<" : "<<scc_num[i]<<endl;
    }

    condensed_g.resize(cur_scc+1);
    for(int i=1;i<=n;i++){
        for(auto v:g[i]){
            if(scc_num[i]!=scc_num[v]){
                condensed_g[scc_num[i]].push_back(scc_num[v]);
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