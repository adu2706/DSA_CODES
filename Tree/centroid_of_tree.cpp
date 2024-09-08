#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

//centroid of a tree is a node where if that node is rooted every subtree connected to that root node have size less than equal to N/2
//centre not equal to centroid always

vector<int> g[200200];
int par[200200];
int subtreeSz[200200];
int dep[200200];
int num_child[200200];
int is_leaf[200200];

int n;

void dfs(int node, int parent, int depth){
    par[node] = parent;
    dep[node] = depth;

    subtreeSz[node] = 1;
    num_child[node] = 0;

    for(auto v:g[node]){
        if(v!=parent){
            num_child[node]++;
            dfs(v,node,depth+1);
            subtreeSz[node]+=subtreeSz[v];
        }
    }
    if(num_child[node]==0){
        is_leaf[node] = 1;
    }
}

int dfs1(int node, int parent){
    for(auto v:g[node]){
        if(v!=parent){
            if(subtreeSz[v] > n/2){
                return dfs1(v,node);
            }
        }
    }
    return node;
}
void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0,0);
    int centroid = dfs1(1,0);
    cout<<centroid<<endl;
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