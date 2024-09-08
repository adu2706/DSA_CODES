#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<int> g[200200];
int dep[200200];
int par[200200];
int numChild[200200];
int subtreeSz[200200];
int is_leaf[200200];

void dfs(int node, int parent, int depth){
    par[node] = parent;
    dep[node] = depth;

    numChild[node] = 0;
    subtreeSz[node] = 1;

    for(auto v:g[node]){
        if(v!=parent){
            numChild[node]++;
            dfs(v,node,depth+1);
            subtreeSz[node]+=subtreeSz[v];
        }
    }

    if(numChild[node]==0){
        is_leaf[node] = 1;
    }
}

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0,0);
    
    int sum_distance = 0;
    for(int i=1;i<=n;i++){
        sum_distance += subtreeSz[i]*(n-subtreeSz[i]);
    }

    cout<<sum_distance<<endl;
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