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
vector<int> par;
vector<int> dep;
vector<int> indp;
vector<int> outdp;
vector<int> ans;


void in_dfs(int node,int parent){
    par[node] = parent;
    indp[node] = 0;
    
    for(auto v:g[node]){
        if(v!=parent){
            in_dfs(v,node);
            indp[node] = max(indp[node],indp[v]+1);
        }
    }
}

void out_dfs(int node, int parent, int outVal){
    //save outdp of node
    outdp[node] = outVal;

    int max1=-1,max2=-1;

    for(auto v:g[node]){
        if(v!=parent){
            if(indp[v]>max1){
                // max2<=max1<indp[v]
                //max2 = max1
                //max1 = indp[v]
                max2 = max1;
                max1 = indp[v];
            }else if(indp[v]>max2){
                //max1>indp[v]>max2
                //max2 = indp[v]
                max2 = indp[v];
            }
        }
    }

    //calculating outdp for child
    for(auto v:g[node]){
        if(v!=parent){
            if(indp[v]==max1){
                out_dfs(v,node,max(max2+2,outdp[node]+1));
            }else{
                out_dfs(v,node,max(max1+2,outdp[node]+1));
            }
        }
    }


}


void solve(){
    int n;
    cin>>n;
    g.resize(n+1);
    par.resize(n+1);
    dep.resize(n+1);
    indp.assign(n+1,0);
    outdp.assign(n+1,0);
    ans.assign(n+1,0);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    in_dfs(1,0);
    out_dfs(1,0,0);

    for(int i=1;i<=n;i++){
        ans[i] = max(indp[i],outdp[i]);
    } 
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }    
    cout<<endl;  
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