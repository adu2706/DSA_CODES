#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<vector<pair<int,pair<int,int>>>> g;
vector<vector<int>> vis,dis;
vector<int> refueling;
int n,m,k;

void dijsktra(pair<int,int> sc){
    vis.assign(n+1,vector<int>(k+1,0));
    dis.assign(n+1,vector<int>(k+1,1e18));

    priority_queue<pair<int,pair<int,int>>> pq;  //{distance,{current node, how much fuel i have}}
    dis[sc.F][sc.S] = 0;
    pq.push({-dis[sc.F][sc.S],sc});

    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();

        int cur_dist = -curr.F;
        pair<int,int> cur_st = curr.S;

        if(vis[cur_st.F][cur_st.S]){
            continue;
        }else{
           vis[cur_st.F][cur_st.S] = 1;
        }

        //try and go to neighbour
        for(auto v:g[cur_st.F]){
            int cur_petrol = cur_st.S;
            int pertrol_req = v.S.F;
            int weight  = v.S.S;
            int neigh = v.F;
            if(cur_petrol>=pertrol_req){
                if(dis[neigh][cur_petrol-pertrol_req]>dis[cur_st.F][cur_st.S]+(0)){
                    //zero added cost because no refueiling is required
                    //this dis vector storing minimum refueling cost to reach destination
                    dis[neigh][cur_petrol-pertrol_req]=dis[cur_st.F][cur_st.S]+(0);
                    pq.push({-dis[neigh][cur_petrol-pertrol_req],{neigh,cur_petrol-pertrol_req}});
                }
            }
        }

        //refill

        if(cur_st.S + 1 <= k &&  dis[cur_st.F][cur_st.S + 1]>dis[cur_st.F][cur_st.S]+refueling[cur_st.F]){
            dis[cur_st.F][cur_st.S + 1]=dis[cur_st.F][cur_st.S]+refueling[cur_st.F];
            pq.push({-dis[cur_st.F][cur_st.S + 1],{cur_st.F,cur_st.S + 1}});
        }
    }
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    refueling.resize(n+1);
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        int p,d;
        cin>>p;
        d=10;
        //how much petrol required to travel d distance
        
        g[a].push_back({b,{p,d}});
        g[b].push_back({a,{p,d}});
    }
    for(int i=1;i<=n;i++){
        cin>>refueling[i];
    }
    int st_node;
    int en_node;
    cin>>st_node>>en_node;
    cin>>k;
    pair<int,int> st = {st_node,0}; // starting node and fuel i have
    dijsktra(st);
    int minimum_refueling = 1e18;
    for(int i=0;i<=k;i++){
        minimum_refueling = min(minimum_refueling,dis[en_node][i]);
    }
    cout<<minimum_refueling<<endl;
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