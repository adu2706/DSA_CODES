#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

void tower_hanoi(int x, string source, string target, string help){
    if(x==0){
        return;
    }

    tower_hanoi(x-1,source,help,target);
    cout<<"Move Disc "<<x<<" from "<<source<<" to "<<target<<endl;
    tower_hanoi(x-1,help,target,source);
}

void solve(){
    tower_hanoi(4,"Source","Target","Help");
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