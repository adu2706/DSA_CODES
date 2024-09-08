#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

const int BoardSize = 4;
const int CellSize = 2;

int board[BoardSize][BoardSize];

/*
0 1 0 0
0 0 4 0
0 4 0 0 
0 0 3 0
*/

bool check(int ch, int row, int col){
    //check int row
    for(int c=0;c<BoardSize;c++){
        if(c!=col && board[row][c]==ch){
            return false;
        }
    }

    //check int col
    for(int r=0;r<BoardSize;r++){
        if(r!=row && board[r][col]==ch){
            return false;
        }
    }

    //check in square
    int str = (row/CellSize)*CellSize;
    int stc = (col/CellSize)*CellSize;

    for(int dx=0;dx<CellSize;dx++){
        for(int dy=0;dy<CellSize;dy++){
            int nx = str+dx;
            int ny = stc+dy;
            if(nx!=row && ny!=col && board[nx][ny]==ch){
                return false;
            }
        }
    }

    return true;
}

int ans=0;

void rec(int row, int col){
    if(col==BoardSize){
        rec(row+1,0);
        return;
    }
    if(row==BoardSize){
        //base case
        ans++;
        cout<<"Answer : "<<ans<<endl;
        for(int i=0;i<BoardSize;i++){
            for(int j=0;j<BoardSize;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }

    if(board[row][col]==0){
        // we need to fill
        for(int ch=1;ch<=BoardSize;ch++){
            if(check(ch,row,col)){
                board[row][col] = ch;
                rec(row,col+1);
                board[row][col] = 0;
            }
        }
    }else{
        //pre filled
        if(check(board[row][col],row,col)){
            rec(row,col+1);
        }
    }
}

void solve(){
   for(int i=0;i<BoardSize;i++){
    for(int j=0;j<BoardSize;j++){
        cin>>board[i][j];
    }
   }
    rec(0,0);
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