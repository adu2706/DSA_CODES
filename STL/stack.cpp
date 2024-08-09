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
   int q;
   cin>>q;
   stack<int> st;
   while(q--){
    string s;
    cin>>s;
    if(s=="add"){
        int x;
        cin>>x;
        st.push(x);
    }else if(s=="remove"){
        if(!st.empty()){
            st.pop();
        }
    }else{
        if(!st.empty()){
            cout<<st.top()<<endl;
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