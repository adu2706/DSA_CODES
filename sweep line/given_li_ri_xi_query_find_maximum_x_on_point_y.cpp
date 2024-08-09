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
    vector<pair<int,pair<int,int>>> events;
    for(int i=0;i<n;i++){
        int l,r,x;
        cin>>l>>r>>x;
        events.push_back({l,{0,x}});
        events.push_back({r,{2,x}});
    }

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int y;
        cin>>y;
        events.push_back({y,{1,i}});
    }

    sort(events.begin(),events.end());
    multiset<int> mt;
    int ans[q];
    for(int i=0;i<events.size();i++){
        if(events[i].S.F == 0){
            //insert
            mt.insert(events[i].S.S);
        }else if(events[i].S.F == 1){
            //query
            if(!mt.empty()){
                ans[events[i].S.S] = *mt.rbegin();
            }else{
                ans[events[i].S.S] = 0;
            }
        }else{
            //remove
            mt.erase(mt.find(events[i].S.S));
        }
    }
    
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
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