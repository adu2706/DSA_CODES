#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

// 1 = left
// 2 = right
// 3 = up
// 4 =  down

using state = pair<int,int>;
int n,m;
vector<vector<int>>g;
vector<vector<int>>dis;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int is_valid(int x,int y){
    if(x<0||x>=n||y<0||y>=m){
        return 0;
    }else{
        return 1;
    }
}

vector<pair<state,int>> neighbours(state cur){
    vector<pair<state,int>> ans;
    for(int i=0;i<4;i++){
        int nx = cur.F + dx[i];
        int ny = cur.S + dy[i];
        if(is_valid(nx,ny)){
            if(g[cur.F][cur.S]==1){
                if(dx[i]==0 && dy[i]==1){
                    ans.push_back({{nx,ny},0});
                }else{
                    ans.push_back({{nx,ny},1});
                }
            }else if(g[cur.F][cur.S]==2){
                 if(dx[i]==0 && dy[i]==-1){
                    ans.push_back({{nx,ny},0});
                }else{
                    ans.push_back({{nx,ny},1});
                }
            }else if(g[cur.F][cur.S]==3){
                 if(dx[i]==1 && dy[i]==0){
                    ans.push_back({{nx,ny},0});
                }else{
                    ans.push_back({{nx,ny},1});
                }
            }else if(g[cur.F][cur.S]==4){
                 if(dx[i]==-1 && dy[i]==0){
                    ans.push_back({{nx,ny},0});
                }else{
                    ans.push_back({{nx,ny},1});
                }
            }
        }

    }
    return ans;
}

void bfs(state st){
    dis = vector<vector<int>>(n,vector<int>(m,INF));
    deque<state> dq;
    dis[st.F][st.S]=0;
    dq.push_back(st);
    
    while(!dq.empty()){
        state cur = dq.front();
        dq.pop_front();

        for(auto v:neighbours(cur)){
            state neigh = v.F;
            int weight = v.S;
            if(dis[neigh.F][neigh.S]>dis[cur.F][cur.S]+weight){
                dis[neigh.F][neigh.S] = dis[cur.F][cur.S]+weight;
                if(weight==0){
                    dq.push_front(neigh);
                }else{
                    dq.push_back(neigh);
                }
            }
        }
    }

}

void printer(vector<vector<int>>xx){
    for(auto v:xx){
        for(auto u:v){
            cout<<u<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void solve(){
   cin>>n>>m;
   g.assign(n,vector<int>(m,0));
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        int x;
        cin>>x;
        g[i][j] = x;
    }
   }
   bfs({0,0});
   //printer(dis);
   cout<<dis[n-1][m-1]<<endl;
    
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