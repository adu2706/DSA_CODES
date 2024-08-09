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
   int q;
   cin>>q;
   map<string,int> mp;
   while(q--){
    string s;
    cin>>s;
    if(mp.find(s)==mp.end()){
        cout<<"OK"<<endl;
        mp[s]++;
    }else{
        cout<<s+to_string(mp[s])<<endl;
        mp[s]++;
    }
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