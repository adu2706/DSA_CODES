#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


struct bag{
    int K;
    multiset<int> mt1,mt2;
    int sumK;
    
    void init(int _K){
        K = _K;
        mt1.clear();
        mt2.clear();
        sumK = 0;
    }

    void insert(int x){
        mt1.insert(x);
        sumK += x;
        if(mt1.size()>K){
            auto it = mt1.begin();
            sumK-= *it;
            mt2.insert(*it);
            mt1.erase(it);
        }
    }
    
    void remove(int x){
        if(mt1.find(x)!=mt1.end()){
            mt1.erase(mt1.find(x));
            sumK-=x;
        }else if(mt2.find(x)!=mt2.end()){
            mt2.erase(mt2.find(x));
        }

        if(mt1.size()<K && !mt2.empty()){
            auto it = mt2.end();
            it--;
            int val = *it;
            mt2.erase(it);
            mt1.insert(val);
            sumK+=val;
        }
    }

    int getSum(){
        return sumK;
    }
};


void solve(){
    int k;
    cin>>k;
    bag bg;
    bg.init(k);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        if(s=="insert"){
            int x;
            cin>>x;
            bg.insert(x);
        }else if(s=="remove"){
            int x;
            cin>>x;
            bg.remove(x);
        }else{
            cout<<bg.getSum()<<endl;
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