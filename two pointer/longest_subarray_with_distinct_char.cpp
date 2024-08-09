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
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }


   map<int,int> freq;
   int ans = 0;
   int head=-1;
   int tail = 0;
   
   
   while(tail<n){
    while(head+1<n && freq[arr[head+1]]==0){
        head++;
        freq[arr[head]]=1;
    }
    ans = max(ans,head-tail+1);

    if(head>=tail){
        freq[arr[tail]]=0;
        tail++;
    }else{
        tail++;
        head=tail-1;
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