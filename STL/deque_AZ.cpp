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
   deque<int> dq;
   while(q--){
    string s;
    cin>>s;
    if(s=="insertback"){
        int x;
        cin>>x;
        dq.push_back(x);
    }else if(s=="eraseback"){
        if(!dq.empty()){
            dq.pop_back();
        }
    }else if(s=="insertfront"){
        int x;
        cin>>x;
        dq.push_front(x);
    }else if(s=="erasefront"){
        if(!dq.empty()){
            dq.pop_front();
        }
    }else if(s=="printfront"){
        if(!dq.empty()){
            cout<<dq.front()<<endl;
        }else{
            cout<<0<<endl;
        }
    }else if(s=="printback"){
        if(!dq.empty()){
            cout<<dq.back()<<endl;
        }else{
            cout<<0<<endl;
        }
    }else if(s=="print"){
        int x;
        cin>>x;
        if(dq.size()>=x+1){
            cout<<dq[x]<<endl;
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