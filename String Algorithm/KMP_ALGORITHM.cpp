#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<int> kmp(string s){
    int n = s.length();
    vector<int> res(n+1);
    res[0] = -1;
    
    int i=0,j=-1;
    while(i<n){
        while(j!=-1 && s[i]!=s[j]){
            j=res[j];
        }
        j++;
        i++;
        res[i] = j; 
    }

    return res;
}

//at paticular index i how much length of suffix at i matching with prifix at 0 index(starting), condition is proper substring
void solve(){
   string s;
   cin>>s;
   vector<int> KMP = kmp(s);
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