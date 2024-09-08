#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 10000
int mod = 1e9+7;

int skip[10][10];
int vis[10];

int rec(int cur, int left){
    if(left == 0) {
        return 1;
    }

    int ans = 0;
    for(int i = 1; i <= 9; i++) {
        if(!vis[i] && (skip[cur][i] == 0 || vis[skip[cur][i]])) {
            vis[i] = 1;
            ans += rec(i, left - 1);
            vis[i] = 0;
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;

    // We are numbering
    // 1 2 3
    // 4 5 6
    // 7 8 9
    memset(skip, 0, sizeof(skip));

    skip[1][3] = skip[3][1] = 2;
    skip[1][7] = skip[7][1] = 4;
    skip[7][9] = skip[9][7] = 8;
    skip[3][9] = skip[9][3] = 6;

    skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;

    int ans = 0;
    memset(vis, 0, sizeof(vis));
    
    vis[1] = 1;
    ans += rec(1, n - 1) * 4;
    
    memset(vis, 0, sizeof(vis));
    vis[2] = 1;
    ans += rec(2, n - 1) * 4;
    
    memset(vis, 0, sizeof(vis));
    vis[5] = 1;
    ans += rec(5, n - 1);

    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
