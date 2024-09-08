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
int n;

void rec(int level){
    if(level == n){
        for(auto v : ans){
            cout << v << " ";
        }
        cout << endl;
        return;
    }

    for(auto &v : mp){
        if(v.second){
            ans.push_back(v.first);
            v.second--;
            rec(level + 1);
            v.second++;
            ans.pop_back();
        }
    }
}

void solve(){
   cin >> n;
   for(int i = 0; i < n; i++){
       int x;
       cin >> x;
       mp[x]++;
   }
   rec(0);  
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
