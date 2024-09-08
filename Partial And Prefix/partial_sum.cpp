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
   int n,m,q;
   cin>>n>>m>>q;
   int arr[n][m];
   memset(arr,0,sizeof(arr));

   while(q--){
    int x1,y1,x2,y2,C;
    cin>>x1>>y1>>x2>>y2>>C;
    x1--;
    y1--;
    x2--;
    y2--;
    arr[x1][y1] += C;
    if(x2+1<n && y2+1<m){
        arr[x2+1][y2+1] += C;
    }

    if(y2+1<m){
        arr[x1][y2+1] -= C;
    }

    if(x2+1<n){
        arr[x2+1][y1] -= C;
    }
   }

   int prefix_sum[n][m];
   memset(prefix_sum,0,sizeof(prefix_sum));

    for(int i = 0; i < n; i++){
       for(int j = 0; j < m; j++){
           prefix_sum[i][j] = arr[i][j];
           if(i > 0){
               prefix_sum[i][j] = prefix_sum[i][j] + prefix_sum[i-1][j];
           }
           if(j > 0){
               prefix_sum[i][j] = prefix_sum[i][j] + prefix_sum[i][j-1];
           }
           if(i > 0 && j > 0){
               prefix_sum[i][j] = prefix_sum[i][j] - prefix_sum[i-1][j-1];
           }
       }
   }

    int maxi = INT_MIN;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        maxi = max(maxi,prefix_sum[i][j]);
    }
   }

   int cnt = 0;
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(prefix_sum[i][j]==maxi){
            cnt++;
        }
    }
   }

   cout<<maxi<<" "<<cnt<<endl;
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