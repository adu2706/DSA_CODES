#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

// class LRUCache{
//     list<int> order;
//     unordered_map<int,pair<int,list<int>::iterator>> cache;
//     int maxsize = 0;

//     void touch(int id){
//         auto it = cache.find(id);
//         int key = it->first;
//         order.erase(it->second.second);
//         order.push_front(key);
//         it->second.second = order.begin();
//     }

// public:
//     LRUCache(int capacity){
//         maxsize = capacity;
//         order.clear();
//         cache.clear();
//     }    

//     int get(int key{
//         if(cache.find(key)==cache.end()){
//             return -1;
//         }else{
//             touch(key);
//             return cache[key].first;
//         }
//     }

//     void put(int key, int val){
//         if(cache.find(key)==cache.end()){
//             if(cache.size()==maxsize){
//                 int del = order.back();
//                 cache.erase(del);
//                 order.pop_back();
//             }
//             order.push_front(key);
//         }else{
//             touch(key);
//         }

//         cache[key] = make_pair(val,order.begin());
//     }
// };

struct LRUCache {
    list<int> order;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    int maxsize;

    LRUCache(int capacity){
        maxsize = capacity;
        order.clear();
        cache.clear();
    }

    void touch(int id) {
        auto it = cache.find(id);
        int key = it->first;
        order.erase(it->second.second);
        order.push_front(key);
        it->second.second = order.begin();
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        } else {
            touch(key);
            return cache[key].first;
        }
    }

    void put(int key, int val) {
        if (cache.find(key) == cache.end()) {
            if (cache.size() == maxsize) {
                int del = order.back();
                cache.erase(del);
                order.pop_back();
            }
            order.push_front(key);
        } else {
            touch(key);
        }
        cache[key] = make_pair(val, order.begin());
    }
};



void solve(){
   int q,cap;
   cin>>q>>cap;

   LRUCache lru(cap);

    while(q--){
        string s;
        cin>>s;
        if(s=="put"){
            int x,y;
            cin>>x>>y;
            lru.put(x,y);
        }else{
            int x;
            cin>>x;
            cout<<lru.get(x)<<endl;
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