#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

void solve(){
   int n, q;
   cin >> n>> q;
   int arr[n][n];
   for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
            char ch;
            cin>>ch;
            if(ch=='.'){
                arr[i][j]=0;
            }else{
                arr[i][j]=1;
            }
       }
   }

   int prefix_sum[n][n];
   memset(prefix_sum, 0, sizeof(prefix_sum));

   for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
           prefix_sum[i][j] = (arr[i][j] + mod) % mod;
           if(i > 0){
               prefix_sum[i][j] = (prefix_sum[i][j] + prefix_sum[i-1][j]) % mod;
           }
           if(j > 0){
               prefix_sum[i][j] = (prefix_sum[i][j] + prefix_sum[i][j-1]) % mod;
           }
           if(i > 0 && j > 0){
               prefix_sum[i][j] = (prefix_sum[i][j] - prefix_sum[i-1][j-1] + mod) % mod;
           }
       }
   }

   while(q--){
       int x1, y1, x2, y2;
       cin >> x1 >> y1 >> x2 >> y2;
       x1--; y1--; x2--; y2--;

       int ans = (prefix_sum[x2][y2] + mod) % mod;
       if(x1 > 0){
           ans = (ans - prefix_sum[x1-1][y2] + mod) % mod;
       }
       if(y1 > 0){
           ans = (ans - prefix_sum[x2][y1-1] + mod) % mod;
       }
       if(x1 > 0 && y1 > 0){
           ans = (ans + prefix_sum[x1-1][y1-1] + mod) % mod;
       }
       cout << ans % mod << endl;
   }
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
