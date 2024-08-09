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
   int m = (1<<n);
   multiset<int> mt;
   for(int i=0;i<m;i++){
    int x;
    cin>>x;
    mt.insert(x);
   }

   multiset<int> org,done;
   done.insert(0);
   mt.erase(mt.find(0));

   while(!mt.empty()){
        int curr = *mt.begin();
        org.insert(curr);

        multiset<int> temp;
        for(auto v:done){
            temp.insert(curr+v);
        }

        for(auto v:temp){
            done.insert(v);
            mt.erase(mt.find(v));
        }
   }

   for(auto v:org){
    cout<<v<<" ";
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