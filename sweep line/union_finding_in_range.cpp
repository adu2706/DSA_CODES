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
    int n;
    cin>>n;
    vector<pair<int,int>> events;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        events.push_back({l,+1});
        events.push_back({r,-1});
    }

    sort(events.begin(),events.end());
    int cnt = 0;
    int uni = 0;
    int inter = 0;
    for(int i=0;i<events.size()-1;i++){
        cnt+=events[i].S;
        if(cnt>0){
            uni+=events[i+1].F-events[i].F;
        }
        if(cnt==n){
            inter+=events[i+1].F-events[i].F;
        }
    }

        //union length
    cout<<uni<<endl;
    //intersection length
    cout<<inter<<endl;
    
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