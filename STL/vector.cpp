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
    vector<int> v;
    while(q--){
        string s;
        cin>>s;
        if(s=="add"){
            int x;
            cin>>x;
            v.push_back(x);
        }else if(s=="print"){
            int x;
            cin>>x;
            if(v.size()>x){
                cout<<v[x]<<endl;
            }else{
                cout<<0<<endl;
            }
        }else if(s=="remove"){
            if(!v.empty()){
                v.pop_back();
            }
        }else{
            v.clear();
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