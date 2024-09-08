#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

multiset<int> mt;
int ans[200200];
vector<int> g[200200];
int val[200200];

void insert(int val){
    mt.insert(val);
}
void remove(int val){
    mt.find(mt.erase(val));
}   

int query(int val){
    int ans = -1e9;
    if(!mt.empty()){
        ans = max(ans,abs(*mt.rbegin()-val));
        ans = max(ans,abs(*mt.begin()-val));
    }
    return ans;
}

void dfs(int node, int par){
    ans[node] = query(val[node]);
    insert(val[node]);

    for(auto v:g[node]){
        if(v!=par){
            dfs(v,node);
        }
    }
    remove(val[node]);
}

void solve(){
   int n;
   cin>>n;
   for(int i=0;i<n-1;i++){
    int a,b,Val1,Val2;
    cin>>a>>b>>Val1>>Val2;
    val[a] = Val1;
    val[b] = Val2;
    g[a].push_back(b);
    g[b].push_back(a);
   }
    dfs(1,0);
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