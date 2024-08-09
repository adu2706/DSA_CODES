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
   stack<int> st1,st2;
   while(q--){
    string s;
    cin>>s;
    if(s=="push"){
        int x;
        cin>>x;
        st1.push(x);
    }else if(s=="pop"){
        if(!st2.empty()){
            cout<<st2.top()<<endl;
            st2.pop();
        }else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            cout<<st2.top()<<endl;
            st2.pop();
        }
    }else{
        if(!st2.empty()){
            cout<<st2.top()<<endl;
        }else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            cout<<st2.top()<<endl;
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