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
   int n,k;
   cin>>n>>k;
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }

   int head = -1;
   int tail = 0;
    //data structure
   int cnt = 0;
    //answer update
   int ans = 0;
   
   while(tail<n){
    while(head+1<n && (arr[head+1]==1 || cnt<k)){
        head++;
        if(arr[head]==0){
            cnt++;
        }
    }

    ans = max(ans,head-tail+1);

    if(head>=tail){
        if(arr[tail]==0){
            cnt--;
        }
        tail++;
    }else{
        tail++;
        head = tail-1;
    }
   }

   cout<<ans<<endl;
    
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}