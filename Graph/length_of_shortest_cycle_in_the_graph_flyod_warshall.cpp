#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int dist[505][505];
void solve(){
   int n,m;
   cin>>n>>m;

   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        dist[i][j]=1e18;
    }
   }

   for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--,b--;
    dist[a][b] = min(dist[a][b],c);
   }

   for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
   }
    
    int short_cycle = 1e18;
    for(int i=0;i<n;i++){
        short_cycle = min(short_cycle,dist[i][i]);
    }
    cout<<short_cycle<<endl;
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