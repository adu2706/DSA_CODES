#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

// all can be same
void solve(){
   int n,target;
   cin>>n>>target;

   vector<int> arr(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }

   map<int,int> mp;
   for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        mp[arr[i]+arr[j]]=1;
    }
   }

   int all_pos = 0;
   
    for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        if(mp[target-(arr[i]+arr[j])]){
            all_pos++;
        }
    }
   }
   cout<<all_pos<<endl;
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