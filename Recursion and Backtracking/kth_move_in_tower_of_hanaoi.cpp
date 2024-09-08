#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

void kthMove(int disc, int source, int target, int help, int k){
    //move disc-1 from source to help  = (2^(disc-1)-1)moves total
    if(k<=((1<<(disc-1))-1)){
        kthMove(disc-1,source,help,target,k);
    }

    //move 1 disc from source to target = 1 moves
    if(k==(1<<(disc-1))){
        cout<<"Moving disc "<<disc<<" from "<<source<<" to "<<target<<endl;
    }
    //move disc-1 from help to target = (2^(disc-1)-1)moves total
    else{
        kthMove(disc-1,help,target,source,k-(1<<(disc-1)));
    }
}


void solve(){
   
    
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