#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
#define endl '\n'
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


void solve(){
   int n,m;
   cin>>n>>m;
   map<int,int> mp;
   while(n--){
    int x;
    cin>>x;
    mp[x]++;
   }
   while(m--){
    int x;
    cin>>x;
    if(mp.find(x)!=mp.end()){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    mp[x]++;
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