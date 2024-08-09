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
   deque<int> dq;
   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    dq.push_back(x);
   }

   int maxi = INT_MIN;
   int idx_maxi;
   for(int i=0;i<n;i++){
    if(dq[i]>maxi){
        maxi = dq[i];
        idx_maxi = i;
    }
   }

   vector<pair<int,int>> v;
   v.push_back({0,0});
   for(int i=0;i<=idx_maxi;i++){
    int a = dq.front();
    dq.pop_front();
    int b = dq.front();
    dq.pop_front();
    v.push_back({a,b});
    if(a>b){
        dq.push_front(a);
        dq.push_back(b);
    }else{
        dq.push_front(b);
        dq.push_back(a);
    }
   }
   dq.pop_front();
    n--;
    while(q--){
        int x;
        cin>>x;
        if(x<v.size()){
            cout<<v[x].first<<" "<<v[x].second<<endl;
        }else{
            cout<<maxi<<" "<<dq[(x-v.size())%n]<<endl;
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