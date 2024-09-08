#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


vector<int> fourSum(vector<int> arr,int n,int target){
    vector<int> sol;
    map<int,pair<int,int>> mp;

    for(int b=n-2;b>=1;b--){
        for(int a=b-1;a>=0;a--){
            if(mp.find(target-(arr[a]+arr[b]))!=mp.end()){
                sol = {a,b,mp[target-(arr[a]+arr[b])].first,mp[target-(arr[a]+arr[b])].second};
                return sol;
            }
        }
        int c = b;
        for(int d=c+1;d<n;d++){
            mp[arr[c]+arr[d]]={c,d};
        }
    }
    return sol;
}


void solve(){
   int n,target;
   cin>>n>>target;
   vector<int> arr(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }

   vector<int> x = fourSum(arr,n,target);
   if(x.size()){
    cout<<"Yes"<<endl;
    for(auto v:x){
        cout<<v<<" ";
    }
    cout<<endl;
   }else{
    cout<<"No"<<endl;
   }
    
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