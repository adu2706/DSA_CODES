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
    int n,R,c,r;
    cin>>n>>R>>c>>r;
    g.clear();
    g.resize(n+1);
    for(int i=0;i<R;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int color = 0;
    vis.assign(n+1,0);
    vector<int> comp(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            color++;
            num_node = 0;
            dfs(i,color);
            comp[color] = num_node;
        }
    }

    int total_clinic = color;
    int total_road = 0;
    for(int i=1;i<=color;i++){
        total_road += comp[i]-1;
    }

    if(r<=c){
        cout<<(total_clinic*c) + (total_road*r)<<endl;
    }else{
        cout<<(n)*c<<endl;
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