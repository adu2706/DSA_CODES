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
vector<string> all_sol;
string s;

int depth = 0;
void rec(int level){
    if(level==n){
        if(depth==0){
            all_sol.push_back(s);
        }
        return;
    }

        s.push_back('(');
        depth++;
        rec(level+1);
        depth--;
        s.pop_back();
    

    if(depth>0){
        s.push_back(')');
        depth--;
        rec(level+1);
        depth++;
        s.pop_back();
    }
    
}


void solve(){
   cin>>n;
   rec(0);

   for(auto v:all_sol){
    cout<<v<<endl;
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