#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


int fourSum(vector<int> arr,int n,int target){
    int res=0;
    map<int,int> mp;

    for(int b=n-2;b>=1;b--){
        for(int a=b-1;a>=0;a--){
            res += mp[target-(arr[a]+arr[b])];
        }
        int c = b;
        for(int d=c+1;d<n;d++){
            mp[arr[c]+arr[d]]++;
        }
    }
    return res;
}


void solve(){
   int n,target;
   cin>>n>>target;
   vector<int> arr(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }

   int numof_sol = fourSum(arr,n,target);
   cout<<"total number of solution is "<<numof_sol<<endl;
    
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