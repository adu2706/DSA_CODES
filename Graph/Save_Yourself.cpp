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
vector<vector<int>> visMon,visA,disMon,disA;
vector<vector<pair<int,int>>> par;
int n,m;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool check(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m || g[x][y]==0){
        return 0;
    }
    return 1;
}

vector<pair<int,int>> neighbours(int x,int y){
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

void bfsMon(queue<pair<int,int>> Monocc){
    disMon.assign(n,vector<int>(m,1e9));
    visMon.assign(n,vector<int>(m,0));

    queue<pair<int,int>> q;
    while(!Monocc.empty()){
        auto cur = Monocc.front();
        Monocc.pop();
        disMon[cur.F][cur.S]=0;
        q.push(cur);
    }

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int x = cur.F;
        int y = cur.S;

        if(visMon[x][y]==1){
            continue;
        }else{
            visMon[x][y]=1;
        }

        for(auto neigh:neighbours(x,y)){
            if(disMon[neigh.F][neigh.S]>disMon[x][y]+1){
                disMon[neigh.F][neigh.S]=disMon[x][y]+1;
                q.push(neigh);
            }
        }
    }
}

void bfsA(int x, int y){
    disA.assign(n,vector<int>(m,1e9));
    visA.assign(n,vector<int>(m,0));
    par.assign(n,vector<pair<int,int>>(m,{-1,-1}));
    queue<pair<int,int>> q;
    disA[x][y] = 0;
    par[x][y] = {-1,-1};
    q.push({x,y});

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        int x = cur.F;
        int y = cur.S;

        if(visA[x][y]==1){
            continue;
        }else{
            visA[x][y]=1;
        }

        for(auto neigh:neighbours(x,y)){
            if(disA[neigh.F][neigh.S]>disA[x][y]+1){
                disA[neigh.F][neigh.S]=disA[x][y]+1;
                par[neigh.F][neigh.S] = {x,y};
                q.push(neigh);
            }
        }
    }
}
void solve(){
    cin>>n>>m;

    g.assign(n,vector<int>(m,1));

    queue<pair<int,int>> Monocc;
    pair<int,int> Aocc;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            if(ch=='#'){
                //wall
                g[i][j] = 0;
            }else if(ch=='A'){
                Aocc = {i,j};
            }else if(ch=='M'){
                Monocc.push({i,j});
            }
        }
    }

    bfsMon(Monocc);
    bfsA(Aocc.F,Aocc.S);


    int x = -1, y = -1, dis = 1e9;

    for(int i=0;i<n;i++){
        if(disA[i][0]!=1e9 && (disA[i][0]<disMon[i][0])){
            if(dis>disA[i][0]){
                x = i;
                y = 0;
                dis = disA[i][0];
            }
        }
        if(disA[i][m-1]!=1e9 && (disA[i][m-1]<disMon[i][m-1])){
            if(dis>disA[i][m-1]){
                x = i;
                y = m-1;
                dis = disA[i][m-1];
            }
        }
    }

    for(int j=0;j<m;j++){
        if(disA[0][j]!=1e9 && (disA[0][j]<disMon[0][j])){
            if(dis>disA[0][j]){
                x = 0;
                y = j;
                dis = disA[0][j];
            }
        }
        if(disA[n-1][j]!=1e9 && (disA[n-1][j]<disMon[n-1][j])){
            if(dis>disA[n-1][j]){
                x = n-1;
                y = j;
                dis = disA[n-1][j];
            }
        }
    }

    if(dis!=1e9){
        cout<<"YES"<<endl;
        cout<<dis<<endl;
        string str;
        pair<int,int> root = {-1,-1};
        while(par[x][y] != root){
            int x1 = par[x][y].F;
            int y1 = par[x][y].S;
            if(y1<y){
                str+='R';
            }else if(y1>y){
                str+='L';
            }else if(x1<x){
                str+='D';
            }else if(x1>x){
                str+='U';
            }
            x = x1;
            y = y1;
        }
        reverse(str.begin(),str.end());
        cout<<str<<endl;
    }else{
        cout<<"NO"<<endl;
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