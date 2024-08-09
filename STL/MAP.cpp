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
   map<string,int>mp;
   while(q--){
    string s;
    cin>>s;
    if(s=="add"){
        string x;
        cin>>x;
        int y;
        cin>>y;
        mp[x] = y;
    }else if(s=="erase"){
        string x;
        cin>>x;
        if(mp.find(x)!=mp.end()){
            mp.erase(mp.find(x));
        }
    }else{
        string x;
        cin>>x;
        if(mp.find(x)!=mp.end()){
            cout<<mp[x]<<endl;
        }else{
            cout<<0<<endl;
        }
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