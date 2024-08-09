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
   int n;
   cin>>n;
   multiset<int> mt;
   int cnt = 0;
   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    auto it = mt.upper_bound(x);
    if(it == mt.end()){
        mt.insert(x);
    }else{
        mt.erase(it);
        mt.insert(x);
    }
   }

   cout<<mt.size()<<endl;
   
    
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