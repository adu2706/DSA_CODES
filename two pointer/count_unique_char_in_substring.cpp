#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, vector<int>> occur;
    for(int i = 0; i < n; i++){
        occur[s[i]].push_back(i);
    }

    int ans = 0;
    for(auto v : occur){
        vector<int> curr = v.second;
        int m = curr.size();
        if(m == 1){
            ans += (curr[0] + 1) * (n - curr[0]);
        }else{
            for(int i = 0; i < m; i++){
                int left,right;
                if(i==0){
                    left = (curr[i] + 1);
                    right = (curr[i+1] - curr[i]);
                }else if(i==m-1){
                    left = (curr[i] - curr[i-1]);
                    right = (n - curr[i]);
                }else{
                    left = (curr[i] - curr[i-1]);
                    right = (curr[i+1] - curr[i]);
                }
                ans += left * right;
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
