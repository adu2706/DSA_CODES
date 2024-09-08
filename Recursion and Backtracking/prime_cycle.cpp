#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37};
int n;
int vis[20];
int rec(int level, int prev){
    if(level==n){
        for(auto v:primes){
            if(prev<=n && v==prev+1){
                return 1;
            }
        }
        return 0;
    }
    int ans = 0;
    for(auto v:primes){
        int cur = v-prev;
        if(cur>0 && cur<=n && !vis[cur]){
            vis[cur] = 1;
            ans += rec(level+1,cur);
            vis[cur] = 0;
        }
    }
    return ans;
}

void solve(){
   cin>>n;
   if(n%2){
    cout<<0<<endl;
   }else{
    memset(vis,0,sizeof(vis));
    vis[1] = 1;
    cout<<rec(1,1)<<endl;
   }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}