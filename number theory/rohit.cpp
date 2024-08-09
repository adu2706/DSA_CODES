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
    string s;
    cin>>s;
    int n = s.length();
    int ans = 0;
    int depth=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            depth--;
        }else{
            depth++;
            if(depth>0){
                ans+=depth;
                depth=0;
            }
        }
    }
    cout<<ans+abs(depth)<<endl;
    
}


int getMin(char *s) {
    int n = strlen(s);
    int ans = 0;
    int depth = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            depth--;
        } else {
            depth++;
            if (depth > 0) {
                ans+=depth;
                depth = 0;
            }
        }
    }
    return ans + abs(depth);
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