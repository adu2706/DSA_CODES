#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


void solve(){
   int n,m,q;
   cin>>n>>m>>q;
   vector<vector<int>> dis;
   dis.assign(n+1,vector<int>(n+1,1e18));

   for(int i=1;i<n;i++){
    dis[i][i] = 0;
   }

   for(int i=0;i<m;i++){
    int a,b,w;
    cin>>a>>b>>w;
    dis[a][b] = min(dis[a][b],w);
    //undirected graph
    dis[b][a] = min(dis[b][a],w);
   }

   for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            dis[j][i] = min(dis[j][i],dis[j][k]+dis[k][i]);
        }
    }
   }

   while(q--){
    int a,b;
    cin>>a>>b;
    if(dis[a][b]==1e18){
        cout<<-1<<endl;
    }else{
        cout<<dis[a][b]<<endl;
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