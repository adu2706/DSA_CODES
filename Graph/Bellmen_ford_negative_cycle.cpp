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
   int n,m;
   cin>>n>>m;
   vector<pair<pair<int,int>,int>> edges(m);
   vector<int> dis(n+1,1e18);
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edges[i] = {{a,b},-w};
    }

    dis[1] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u,v,w;
            u = edges[j].F.F;
            v = edges[j].F.S;
            w = edges[j].S;

            if(dis[v]>dis[u]+w){
                dis[v] = dis[u]+w;
            }

        }
    }

    bool neg = false;
    for(int j=0;j<m;j++){
        int u,v,w;
        u = edges[j].F.F;
        v = edges[j].F.S;
        w = edges[j].S;

        if(dis[v]>dis[u]+w){
            neg = true;
            break;
        }

    }


    if(neg){
        cout<<-1<<endl;
    }else{
        cout<<-dis[n]<<endl;
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