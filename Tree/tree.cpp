#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<int> g[100100];

int dep[100100];
int par[100100];
bool isleaf[100100];
int subtreeSz[100100];
int numChild[100100];

void dfs(int node, int parent, int depth){
    dep[node] = depth;
    par[node] = parent;

    numChild[node] = 0;
    subtreeSz[node] = 1;//set this val 

    for(auto v:g[node]){
        if(v!=parent){
            numChild[node]++;
            dfs(v,node,depth+1);
            subtreeSz[node]+=subtreeSz[v];
        }
    }

    if(numChild[node]==0){
        isleaf[node]=1;
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