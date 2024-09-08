#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


/*
(-2,-1) (-2,-1) (-2,0) (-2,1) (-2,2)          
(-1,-2) (-1,-1) (-1,0) (-1,1) (-1,2)
(0,-2)  (0,-1)  (0,0)  (0,1)  (0,2)
(1,-2)  (1,-1)  (1,0)  (1,1)  (1,2)
(2,-2)  (2,-1)  (2,0)  (2,1)  (2,2)
*/
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int knights[14][14];
int n;

int check(int row, int col){
    for(int i = 0; i < 8; i++){
        int nx = row + dx[i];
        int ny = col + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n && knights[nx][ny] == 1){
            return 0;
        }
    }
    return 1;
}

int rec(int row, int col, int k){
    if(k==0){
        return 1;
    }
    if(col==n){
        return rec(row+1,0,k);
    }
    if(row == n){
        return 0;
    }

    int ans = rec(row,col+1,k); 

    if(check(row, col)){
        knights[row][col] = 1;
        ans += rec(row, col+1,k-1);
        knights[row][col] = -1;
    }

    return ans;
}

void solve(){ 
    int k;
    cin >> n >> k;
    memset(knights, -1, sizeof(knights));
    cout << rec(0, 0, k) << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}   