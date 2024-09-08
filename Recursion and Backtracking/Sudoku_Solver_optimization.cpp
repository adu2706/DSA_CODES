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

int takenRow[BoardSize];
int takenCol[BoardSize];
int takenGrid[CellSize][CellSize];

int logtwo[10010];

int ans=0;

int getChoice(int row, int col){
    int taken = (takenRow[row]|takenCol[col]|takenGrid[row/CellSize][col/CellSize]);
    int nottaken = (((1<<(BoardSize+1))-1)^taken);
    if(nottaken&1){
        nottaken ^=1;
    }
    return nottaken;
}

int makeMove(int ch, int row, int col){
    board[row][col] = ch;
    takenRow[row] ^= (1<<ch);
    takenCol[col] ^= (1<<ch);
    takenGrid[row/CellSize][col/CellSize] ^= (1<<ch);
}
int revertMove(int ch, int row, int col){
    board[row][col] = 0;
    takenRow[row] ^= (1<<ch);
    takenCol[col] ^= (1<<ch);
    takenGrid[row/CellSize][col/CellSize] ^= (1<<ch);
}

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
        int chMask = getChoice(row,col);
        while(chMask){
            int last1 = chMask^(chMask&(chMask-1));
            int last1pos = logtwo[last1];
            makeMove(last1pos,row,col);
            rec(row,col+1);
            revertMove(last1pos,row,col);
            chMask = chMask&(chMask-1);
        }
    }else{
        //pre filled (Assume there is a solution)
        rec(row,col+1);
    }
}

void solve(){
    for(int i=0;i<=9;i++){
        logtwo[(1<<i)]=i;
    }
   for(int i=0;i<BoardSize;i++){
    for(int j=0;j<BoardSize;j++){
        cin>>board[i][j];
        makeMove(board[i][j],i,j);
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