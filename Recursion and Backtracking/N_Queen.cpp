#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<int> queen(8,-1);
int n;
bool check(int row, int col){
    for(int prow = 0; prow < row; prow++){
        int pcol = queen[prow];
        //if on same column or same diagonal
        if(pcol == col || abs(row-prow) == abs(col-pcol)){
            return false;
        }
    }
    return true;
}

int rec(int level){
    //level
    if(level == n){
        return 1;
    }
    int ans = 0;
    //choice
    for(int col = 0; col < n; col++){
        //check
        if(check(level, col)){
            queen[level] = col;
            //move
            ans += rec(level + 1);
            queen[level] = -1;
        }
    }
    return ans;
}

void solve(){
    cin >> n;
    cout << rec(0) << endl;
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
