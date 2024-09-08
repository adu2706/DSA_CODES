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
   int n;
   cin>>n;
   int dist[n][n];
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>dist[i][j];
    }
   }

   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
    arr[i]--;
   }
    vector<int> ans;
   for(int k=n-1;k>=0;k--){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j] = min(dist[i][j],dist[i][arr[k]]+dist[arr[k]][j]);
            }
        }
        int temp = 0;
        for(int i=k;i<n;i++){
            for(int j=k;j<n;j++){
                temp+=dist[arr[i]][arr[j]];
            }
        }
        ans.push_back(temp);
   }

   reverse(ans.begin(),ans.end());

   for(auto v:ans){
    cout<<v<<" ";
   }
   cout<<endl;
    
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