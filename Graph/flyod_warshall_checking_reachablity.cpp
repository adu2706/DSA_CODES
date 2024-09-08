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
        if(i!=j){
            dist[i][j]=1e18;
        }else{
            dist[i][j] = 1;
        }
    }
   }

   for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--,b--;
    dist[a][b] = 1;
   }

   for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = dist[i][j]|(dist[i][k]&dist[k][j]);
        }
    }
   }
    
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