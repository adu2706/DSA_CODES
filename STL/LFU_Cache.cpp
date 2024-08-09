#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct LFUCache{
    int capacity,size,lfu=0;
    unordered_map<int,list<int>>keys;
    unordered_map<int,pair<int,int>> values;
    unordered_map<int,list<int>::iterator> iters;

    LFUCache(int cap){
        capacity = cap;
        size = 0;
    }

    void update(int key){
        int freq = values[key].second;
        auto it = iters[key];
        values[key].second++;
        keys[freq].erase(it);
        keys[freq+1].push_back(key);
        iters[key] = --keys[freq+1].end();
        if(keys[lfu].empty()){
            lfu++;
        }
    }

    int get(int key){
        if(values.find(key)==values.end()){
            return -1;
        }
        update(key);
        return values[key].first;
    }

    void put(int key, int val){
        if(!capacity){
            return;
        }

        if(values.find(key)!=values.end()){
            values[key].first = val;
            update(key);
        }else{
            if(size==capacity){
                int evict = keys[lfu].front();
                keys[lfu].pop_front();
                values.erase(evict);
                iters.erase(evict);
            }else{
                size++;
            }
            values[key] = {val,1};
            keys[1].push_back(key);
            iters[key] = --keys[1].end();
            lfu=1;
        }
    }
};

void solve(){
   int q,cap;
   cin>>cap>>q;
   LFUCache lfu(cap);

   while(q--){
    string s;
    cin>>s;
    if(s=="put"){
        int key,val;
        cin>>key>>val;
        lfu.put(key,val);
    }else{
        int key;
        cin>>key;
        cout<<lfu.get(key)<<endl;
    }
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