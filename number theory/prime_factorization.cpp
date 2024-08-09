#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int n;
int sp[10000006];
vector<int> primeFac(int x){
    vector<int> ans;
    while(x>1){
        ans.push_back(sp[x]);
        x/=sp[x];
    }
    return ans;
}

void solve(){ 
   cin>>n;
   for(int i=2;i<=n;i++){
    sp[i]=i;
   }

   for(int i=2;i<=n;i++){
    if(sp[i]==i){
        for(int j=2*i;j<=n;j+=i){
            if(sp[j]==j){
                sp[j]=i;
            }
        }
    }
   }

   vector<vector<int>> all_primefac(n+1);

   for(int i=2;i<=n;i++){
    vector<int> ans = primeFac(i);
    all_primefac[i] = ans;
   }

   for(auto v:all_primefac){
    for(auto u:v){
        cout<<u<<" ";
    }
    cout<<endl;
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