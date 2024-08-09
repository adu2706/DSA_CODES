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
    int cur_sum = 0;
    set<int> st;
    map<int,int>mp;
    void insert(int x){ //O(log(n))
        cur_sum+=x;
        mp[x]++;
    }

    void remove(int x){ //O(log(n))
        cur_sum-=x;
        mp[x]--;
        if(mp[x]==0){
            mp.erase(x);
        }
    }

    int get_sum(){ //O(1)
        return cur_sum;
    }
    int get_max(){ //O(1)
        return (*mp.rbegin()).first;

        // auto it = mp.end();
        // it--; 
        // return it->first;
    }
    int get_distinct(){ //O(1)
        return mp.size();
    }
};

void solve(){
   bag  bg;
   
    
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