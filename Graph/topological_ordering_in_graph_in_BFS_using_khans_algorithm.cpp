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
vector<int> indeg;
vector<int> topo;
int n,m;

void khan(){
    priority_queue<int> pq;//for lexiographically smallest topolocial ordering
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            pq.push(-i);
        }
    }

    while(!pq.empty()){
        int cur = -pq.top();
        pq.pop();
        topo.push_back(cur);
        for(auto v:g[cur]){
            indeg[v]--;
            if(indeg[v]==0){
                pq.push(-v);
            }
        }
    }
}
void solve(){
   cin>>n>>m;
   g.resize(n+1);
   indeg.assign(n+1,0);
   for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    indeg[b]++;
   }

   khan();
   if(topo.size()!=n){
    cout<<"there is a cycle"<<endl;
   }else{
    for(auto v:topo){
    cout<<v<<" ";
   }
   cout<<endl;
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