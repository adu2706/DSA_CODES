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
   multiset<int> mt;
   while(q--){
    string s;
    cin>>s;
    if(s=="add"){
        int x;
        cin>>x;
        mt.insert(x);
    }else if(s=="erase"){
        int x;
        cin>>x;
        if(mt.find(x)!=mt.end()){
             mt.erase(mt.find(x));
        } 
    }else if(s=="eraseall"){
        int x;
        cin>>x;
        if(mt.find(x)!=mt.end()){
             mt.erase(x);
        } 
    }else if(s=="find"){
        int x;
        cin>>x;
        if(mt.find(x)!=mt.end()){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }else if(s=="count"){
        int x;
        cin>>x;
        cout<<mt.count(x)<<endl;
    }else if(s=="print"){
        for(auto x:mt){
            cout<<x<<" ";
        }
        cout<<endl;
    }else{
        mt.clear();
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