#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<string> g;
int n,m;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool check(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m || g[x][y]=='#'){
        return 0;
    }
    return 1;
}

vector<pair<int,int>> neighbour(int x, int y){
    vector<pair<int,int>> ans;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(check(nx,ny)){
            ans.push_back({nx,ny});
        }
    }
    return ans;
}

void bfs(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &dis){
    vis.assign(n,vector<int>(m+1,0));
    dis.assign(n,vector<int>(m+1,1e9));

    deque<pair<int,int>> dq;
    dis[x][y] = 0;
    dq.push_back({x,y});

    while(!dq.empty()){
        auto cur = dq.front();
        dq.pop_front();

        if(vis[cur.F][cur.S]){
            continue;
        }else{
            vis[cur.F][cur.S]=1;
        }

        for(auto neigh:neighbour(cur.F,cur.S)){
            int weight;
            if(g[neigh.F][neigh.S]=='1' || g[neigh.F][neigh.S]=='2' || g[neigh.F][neigh.S]=='3'){
                weight = 0;
            }else if(g[neigh.F][neigh.S]=='.'){
                weight = 1;
            }

            if(dis[neigh.F][neigh.S]>dis[cur.F][cur.S]+weight){
                dis[neigh.F][neigh.S]=dis[cur.F][cur.S]+weight;
                if(weight==0){
                    dq.push_front(neigh);
                }else{
                    dq.push_back(neigh);
                }
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n);
    for(int i=0;i<n;i++){
        cin>>g[i];
    }

    vector<vector<int>> vis1,vis2,vis3,dis1,dis2,dis3;

    int x1,y1,x2,y2,x3,y3;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='1'){
                x1=i;
                y1=j;
            }else if(g[i][j]=='2'){
                x2=i;
                y2=j;
            }else if(g[i][j]=='3'){
                x3=i;
                y3=j;
            }
        }
    }

    bfs(x1,y1,vis1,dis1);
    bfs(x2,y2,vis2,dis2);
    bfs(x3,y3,vis3,dis3);

    int mini_dist = 1e9;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]!='#'){
                int temp = dis1[i][j]+dis2[i][j]+dis3[i][j];
                if(g[i][j]=='.'){
                    temp=temp-2;
                }
                mini_dist = min(mini_dist,temp);
            }
        }
    }

    if(mini_dist==1e9){
        cout<<-1<<endl;
    }else{
        cout<<mini_dist<<endl;
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