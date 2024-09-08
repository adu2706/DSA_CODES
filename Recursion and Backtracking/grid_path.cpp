#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int n = 7;
string s;
int vis[7][7];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int rec(int row, int col, int step){
    if(row==n-1 && col==0){
        return step==48;
    }

    //down wall but not the corner cells
    if((row+1==n) && (col+1>=0 && col+1<n && col-1>=0 && col-1<n) && ((vis[row][col+1]==1 && vis[row][col-1]==1) || (vis[row][col+1]==0 && vis[row][col-1]==0))){
        return 0;
    }

    //right wall but not the corner cells
    if((col+1==n) && (row+1>=0 && row+1<n && row-1>=0 && row-1<n) && ((vis[row+1][col]==1 && vis[row-1][col]==1) || (vis[row+1][col]==0 && vis[row-1][col]==0))){
        return 0;
    }

    //upper wall but not the corner cells
    if((row==0) && (col+1>=0 && col+1<n && col-1>=0 && col-1<n) && ((vis[row][col+1]==1 && vis[row][col-1]==1) || (vis[row][col+1]==0 && vis[row][col-1]==0))){
        return 0;
    }

    //left wall but not the corner cells
    if((col==0) && (row+1>=0 && row+1<n && row-1>=0 && row-1<n) && ((vis[row+1][col]==1 && vis[row-1][col]==1) || (vis[row+1][col]==0 && vis[row-1][col]==0))){
        return 0;
    }

    int ans = 0;
    vis[row][col] = 1;
    if(s[step]=='?'){
        for(int i=0;i<4;i++){
            int nx = row+dx[i];
            int ny = col+dy[i];
            if(nx>=0 && nx<7 && ny>=0 && ny<7 && vis[nx][ny]==0){
                ans += rec(nx,ny,step+1);
            }
        }
    }else if(s[step]=='U'){
        int nx = row-1;
        int ny = col+0;
        if(nx>=0 && nx<7 && ny>=0 && ny<7 && vis[nx][ny]==0){
            ans += rec(nx,ny,step+1);
        }
    }else if(s[step]=='L'){
        int nx = row;
        int ny = col-1;
        if(nx>=0 && nx<7 && ny>=0 && ny<7 && vis[nx][ny]==0){
            ans += rec(nx,ny,step+1);
        }
    }else if(s[step]=='R'){
        int nx = row;
        int ny = col+1;
        if(nx>=0 && nx<7 && ny>=0 && ny<7 && vis[nx][ny]==0){
            ans += rec(nx,ny,step+1);
        }
    }else if(s[step]=='D'){
        int nx = row+1;
        int ny = col;
        if(nx>=0 && nx<7 && ny>=0 && ny<7 && vis[nx][ny]==0){
            ans += rec(nx,ny,step+1);
        }
    }
    vis[row][col] = 0;
    return ans;
}

void solve(){
   cin>>s;
    memset(vis,0,sizeof(vis));
    cout<<rec(0,0,0)<<endl;
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