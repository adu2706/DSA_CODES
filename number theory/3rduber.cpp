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
void dfs(int node){
    vis[node] = 1;
    for(auto neigh:g[node]){
        if(!vis[neigh]){
            dfs(neigh);
        }
    }
}
int fun(int n, vector<string> v){ 
    g.resize(n);
    vector<unordered_set<char>> ch;
    ch.resize(n);
    for(int i=0;i<n;i++){
        for(auto x:v[i]){
            ch[i].insert(x);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(auto x:ch[i]){
                if(ch[j].find(x)!=ch[j].end()){
                    g[i].push_back(j);
                    g[j].push_back(i);
                    break;
                }
            }
        }
    }

    
    vis.assign(n,0);
    int ans = 0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }

    return ans;

}

void solve(){
   int n;
   cin>>n;
   vector<string> v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];
   }

    int ans = fun(n,v);
    cout<<ans<<endl;
    
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