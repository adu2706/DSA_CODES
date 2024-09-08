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
vector<vector<pair<int,int>>> dimensions;
vector<vector<int>> vis;
int n,m;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool check(int x,int y){
    if(x<0 || x>=n || y<0 || y>=m || g[x][y]==0){
        return 0;
    }
    return 1;
}

vector<pair<int,int>> neighbours(int x, int y){
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

void fill_dimension(){
    dimensions.assign(n,vector<pair<int,int>>(m,{0,0}));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int area = 1;
            int perimeter = 0;
            for(int k=0;k<4;k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx<0 || nx>=n || ny<0 || ny>=m){
                    perimeter++;
                }else if(g[nx][ny]==0){
                    perimeter++;
                }
            }
            pair<int,int> x = {area,perimeter};
            dimensions[i][j] = x;
        }
    }
}

int area;
int perimeter;
void dfs(int x, int y){
    vis[x][y] = 1;
    area+=dimensions[x][y].F;
    perimeter+=dimensions[x][y].S;
    for(auto neigh:neighbours(x,y)){
        if(vis[neigh.F][neigh.S]==0){
            dfs(neigh.F,neigh.S);
        }
    }
}

void solve(){
    cin>>n;
    m = n;
    g.assign(n,vector<int>(m,0));
    vis.assign(n,vector<int>(m,0)); 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            if(ch=='#'){
                g[i][j]=1;
            }
        }
    }
    fill_dimension();

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<"{"<<dimensions[i][j].F<<" , "<<dimensions[i][j].S<<"}"<<" ";
    //     }
    //     cout<<endl;
    // }

    int a = 0;
    int p = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && g[i][j]==1){
                area = 0;
                perimeter = 0;
                dfs(i,j);
                if(area>a){
                    a = area;
                    p = perimeter; 
                }else if(area==a && perimeter<p){
                    p = perimeter;
                }
            }
        }
    }
    
    cout<<a<<" "<<p<<endl;
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