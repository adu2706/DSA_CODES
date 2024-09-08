#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<int> sol;
vector<int> arr;
int n;
void rec(int level){
    if(level==n){
        for(auto v:sol){
            cout<<v<<" ";
        }
        cout<<endl;
        return;
    }
    //skip
    rec(level+1);
    //check
    sol.push_back(arr[level]);
    rec(level+1);
    sol.pop_back();
}

void solve(){
   cin>>n;
   arr.clear();
   sol.clear();
   arr.resize(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   rec(0);
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