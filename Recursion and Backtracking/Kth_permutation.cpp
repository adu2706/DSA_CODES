#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

map<int,int> mp;
vector<int> ans;
int n,k;
int fact[14];

void rec(int level, int k){
    if(level == n){
        return;
    }
    int val = 0;
    for(auto &v : mp){
        if(v.second){
            if(k<=val+fact[n-level-1]){
                ans.push_back(v.first);
                v.second--;
                rec(level+1,k-val);
            }
            val+=fact[n-level-1];
        }
    }
}

void solve(){
   cin >> n >>k;
   fact[0] = 1;
   for(int i=1;i<=13;i++){
    fact[i] = fact[i-1]*i;
   }

   if(n<=13){
    for(int i=1;i<=n;i++){
        mp[i]++;
    }
    rec(0,k);
    for(auto v:ans){
        cout<<v<<" ";
    }
    cout<<endl;
   }else{
    for(int i=1;i<=n-13;i++){
        cout<<i<<" ";
    }
    for(int i=n-12;i<=n;i++){
        mp[i]++;
    }
    rec(n-13,k);
    for(auto v:ans){
        cout<<v<<" ";
    }
    cout<<endl;
   }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
