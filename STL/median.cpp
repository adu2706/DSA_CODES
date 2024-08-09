#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


struct bag_median{
    multiset<int> lo,hi;

    void insert(int x){
        if(!lo.empty()){
            auto it = lo.end();
            it--;
            if(x<=*it){
                lo.insert(x);
                return;
            }
        }
        if(!hi.empty()){
            auto it = hi.begin();
            if(x>=*it){
                hi.insert(x);
                return;
            }
        }
        lo.insert(x);
    }

    void erase(int x){
        if(!lo.empty()){
            auto it = lo.end();
            it--;
            if(x<=*it){
                lo.erase(lo.find(x));
                return;
            }
        }
        if(!hi.empty()){
            auto it = hi.begin();
            if(x>=*it){
                hi.erase(hi.find(x));
                return;
            }
        }
    }

    void rebalance(){
        while(lo.size()>hi.size()+1){
            auto it = lo.end();
            it--;
            int val = *it;
            lo.erase(it);
            hi.insert(val);
        }

        while(hi.size()>lo.size()){
            auto it = hi.begin();
            int val = *it;
            hi.erase(it);
            lo.insert(val);
        }
    }

    int get_median(){
        rebalance();
        auto it = lo.end();
        it--;
        return *it;
    }
};

void solve(){
    bag_median bg;
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        if(s=="insert"){
            int x;
            cin>>x;
            bg.insert(x);
        }else if(s=="erase"){
            int x;
            cin>>x;
            bg.erase(x);
        }else{
            cout<<bg.get_median()<<endl;
        }
        
    }
    
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