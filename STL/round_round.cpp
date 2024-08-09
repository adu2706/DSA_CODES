#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

void solve(){
    int x = 0, y = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int dir = 0;  // 0 = N, 1 = E, 2 = S, 3 = W

    for(int i = 0; i < n; i++){
        if(s[i] == 'W'){
            if(dir == 0){
                y++;
            } else if(dir == 1){
                x++;
            } else if(dir == 2){
                y--;
            } else if(dir == 3){
                x--;
            }
        } else if(s[i] == 'L'){
            dir = (dir + 3) % 4;  // turn left (counter-clockwise)
        } else if(s[i] == 'R'){
            dir = (dir + 1) % 4;  // turn right (clockwise)
        }
    }

    // Check if Bob returns to the origin or is not facing north
    if((x == 0 && y == 0) || dir != 0){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
