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
   int n,T;
   cin>>n>>T;
   vector<int> arr;
   arr.resize(n);
   map<int,int> freq;
   for(int i=0;i<n;i++){
    cin>>arr[i];
    freq[arr[i]]++;
   }
   vector<int> brr;
    for(auto x:freq){
        brr.push_back(x.first);
    }
    sort(brr.begin(),brr.end());
    int m = brr.size();
   int ans = 1e18;
   for(int j=1;j<m-1;j++){
        int i=0;
        int k=m-1;
        while(i<j && j<k){
            int sum = brr[i]+brr[j]+brr[k];
            int diff = abs(T-sum);
            ans = min(ans,diff);
            if(sum>T){
                k--;
            }else if(sum==T){
                i++;
                k--;
            }else{
                i++;
            }
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