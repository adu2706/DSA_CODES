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
   int n,k;
   cin>>n>>k;
   map<int,int> freq;
   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    freq[x]++;
   }

   int ans = 1LL*(n)*(n-1)/2;
    priority_queue<int> pq;
    for(auto v:freq){
        if(v.second>1){
            ans -= 1LL*(v.second)*(v.second-1)/2;
            pq.push(v.second);
        }
    }

    

    for(int i=0;i<k;i++){
        if(pq.empty()){
            break;
        } 
        int val = pq.top();
        pq.pop();
        ans += val-1;
        val--;
        if(val>1){
            pq.push(val);
        }
    }

    cout<<ans<<endl;
    
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