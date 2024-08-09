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
   int n,q;
   cin>>n>>q;
   vector<int> l(n),r(n);

   for(int i=0;i<n;i++){
    cin>>l[i]>>r[i];
   }

   sort(l.begin(),l.end());
   sort(r.begin(),r.end());

   while(q--){
    int y;
    cin>>y;
    
    int ri_less_than_y = (lower_bound(r.begin(),r.end(),y)-r.begin());
    int li_greater_than_y = n-(upper_bound(l.begin(),l.end(),y)-l.begin());

    cout<<n-(ri_less_than_y+li_greater_than_y)<<endl;
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