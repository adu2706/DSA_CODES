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
   set<int> st;
   while(q--){
    string s;
    cin>>s;
    if(s=="add"){
        int x;
        cin>>x;
        st.insert(x);
    }else if(s=="erase"){
        int x;
        cin>>x;
        if(st.find(x)!=st.end()){
            st.erase(st.find(x));
        }
    }else if(s=="find"){
        int x;
        cin>>x;
        if(st.find(x)!=st.end()){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }else if(s=="print"){
        for(auto it:st){
            cout<<it<<" ";
        }
        cout<<endl;
    }else{
        st.clear();
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