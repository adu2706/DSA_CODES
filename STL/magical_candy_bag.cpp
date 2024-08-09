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
  priority_queue<int> pq;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    pq.push(x);
  }

  int ans = 0;
  while(k--){
    ans += pq.top();
    int x = pq.top();
    pq.pop();
    pq.push(x/2);
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