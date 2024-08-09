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
   priority_queue<int> pq;
   while(q--){
    string s;
    cin>>s;
    if(s=="add"){
        int x;
        cin>>x;
        pq.push(x);
    }else if(s=="remove"){
        if(!pq.empty()){
            pq.pop();
        }
    }else if(s=="print"){
        if(!pq.empty()){
            cout<<pq.top()<<endl;
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