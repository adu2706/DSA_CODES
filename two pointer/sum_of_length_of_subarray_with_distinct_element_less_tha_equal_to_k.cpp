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

   int ans = 0;
   map<int,int> mp;
   int distinctCnt = 0;

   while(tail<n){
    while(head+1<n && (mp[arr[head+1]]>0 || distinctCnt<k)){
        head++;
        if(mp[arr[head]]==0){
            distinctCnt++;
        }
        mp[arr[head]]++;
    }
    int len = head-tail+1;
    ans += len*(len+1)/2;

    if(head>=tail){
        mp[arr[tail]]--;
        if(mp[arr[tail]]==0){
           distinctCnt--;
        }
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