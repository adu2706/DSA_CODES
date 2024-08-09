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
   priority_queue<int> pq;
   while(n--){
    int x;
    cin>>x;
    pq.push(-x);
   }

    int score = 0;
   while(pq.size()>1){
    int x = pq.top();
    pq.pop();
    int y = pq.top();
    pq.pop();
    score += -1*(x+y);
    pq.push((x+y));
   }

   cout<<score<<endl;
    
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