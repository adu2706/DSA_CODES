#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int dep[200100];
int par[200100];
vector<int> g[200100];

void dfs(int node, int parent, int depth){
    dep[node] = depth;
    par[node] = parent;
    for(auto v:g[node]){
        if(v!=parent){
            dfs(v,node,depth+1);
        }
    }
}

void solve(){
   int n;;
   cin>>n;
   for(int i=0;i<n-1;i++){
    int a,b;;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
   }

   dfs(1,0,0);

   int mach = 1;
   for(int i=1;i<=n;i++){
    if(dep[i]>dep[mach]){
        mach=i;
    }
   }

   dfs(mach,0,0);
   mach = 1;
   for(int i=1;i<=n;i++){
    if(dep[i]>dep[mach]){
        mach=i;
    }
   }
    
    cout<<dep[mach]<<endl;
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