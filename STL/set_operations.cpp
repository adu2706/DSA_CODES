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
   int n,m;
   cin>>n>>m;
   set<int> s1,s2;
   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    s1.insert(x);
    }

   for(int i=0;i<m;i++){
    int x;
    cin>>x;
    s2.insert(x);
   }

    set<int> uni;
    for(auto x:s1){
        uni.insert(x);
    }
    for(auto x:s2){
        uni.insert(x);
    }

    set<int> inter;
    for(auto x:s1){
        if(s2.find(x)!=s2.end()){
            inter.insert(x);
        }
    }

    set<int> diff;
    for(auto x:s1){
        if(s2.find(x)==s2.end()){
            diff.insert(x);
        }
    }

    for(auto x:uni){
        cout<<x<<" ";
    }
    cout<<endl;

    for(auto x:inter){
        cout<<x<<" ";
    }
    cout<<endl;
    

    for(auto x:diff){
        cout<<x<<" ";
    }
    cout<<endl;
    
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