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
vector<vector<int>> vis,dis;
vector<vector<pair<int,int>>> par;
int n,m;

//U,R,D,L
char dirchar[] = {'U','R','D','L'};
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

bool check(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m || g[x][y]=='W'){
        return 0;
    }
    return 1;
}

vector<pair<int,int>> neighbours(int x,int y){
    vector<pair<int,int>> ans;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(check(nx,ny) && g[nx][ny]!='B'){
            ans.push_back({nx,ny});
        }
    }
    return ans;
}
 
void process(vector<vector<pair<int,int>>> pos){
    for(int dir=0;dir<4;dir++){
        for(auto v:pos[dir]){
            int x = v.F+dx[dir];
            int y = v.S+dy[dir];
            while(check(x,y) && g[x][y]!=dirchar[dir]){
                if(g[x][y]=='.'){
                    g[x][y] = 'B';
                }
                x = x+dx[dir];
                y = y+dy[dir];
            }
        }
        for(auto v:pos[dir]){
            int x = v.first;
            int y = v.second;
            g[x][y] = 'B';
        } 
    }
}

void bfs(int x, int y){
    vis.assign(n,vector<int>(m,0));
    dis.assign(n,vector<int>(m,1e18));
    par.assign(n,vector<pair<int,int>>(m,{-1,-1}));
    queue<pair<int,int>> q;
    dis[x][y] = 0;
    par[x][y] = {-1,-1};
    q.push({x,y});

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        if(vis[cur.F][cur.S]){
            continue;
        }else{
            vis[cur.F][cur.S]=1;
        }

        for(auto v:neighbours(cur.F,cur.S)){
            if(dis[v.F][v.S]>dis[cur.F][cur.S]+1){
                dis[v.F][v.S]=dis[cur.F][cur.S]+1;
                par[v.S][v.S] = cur;
                q.push(v);
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

   pair<int,int> st,en;
   vector<vector<pair<int,int>>> pos(4); //U R D L

   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(g[i][j]=='U'){
            pos[0].push_back({i,j});
        }else if(g[i][j]=='R'){
            pos[1].push_back({i,j});
        }else if(g[i][j]=='D'){
            pos[2].push_back({i,j});
        }else if(g[i][j]=='L'){
            pos[3].push_back({i,j});
        }else if(g[i][j]=='S'){
            st = {i,j};
        }else if(g[i][j]=='E'){
            en = {i,j};
        }
        
    }
   }


   process(pos);

   bfs(st.F,st.S);

   if(dis[en.F][en.S]==1e18){
    cout<<"NO path possible"<<endl;
   }else{
    cout<<dis[en.F][en.S]<<endl;
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