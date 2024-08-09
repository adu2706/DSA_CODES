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
   string s;
   cin>>s;
   map<char,int> mp;
   mp['['] = 1;
   mp['{'] = 2;
   mp['('] = 3;
   mp[')'] = -3;
   mp['}'] = -2;
   mp[']'] = -1;
   stack<int> st;
   bool flag = 1;
    for(auto x:s){
        int val = mp[x];
        if(val>0){
            st.push(val);
        }else{
            if(!st.empty() && st.top()+val==0){
                st.pop();
            }else{
                flag = 0;
                break;
            }
        }
    }

    if(!st.empty()){
        flag = 0;
    }

   if(flag){
    cout<<"YES"<<endl;
   }else{
    cout<<"NO"<<endl;
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