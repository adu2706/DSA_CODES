#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
#define endl '\n'
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct queries{
    map<int,int> mp;
    int sum = 0;
    void add(int x){
        mp[x]++;
        sum+=x;
    }

    void remove(int x){
        if(mp.find(x)!=mp.end()){
            mp[x]--;
            if(mp[x]==0){
                mp.erase(x);
            }
            sum-=x;
        }
    }

    int get_min(){
        if(mp.size()!=0){
            return (*mp.begin()).first;
        }else{
            return -1;
        }
    }

    int get_max(){
        if(mp.size()!=0){
            return (*mp.rbegin()).first;
        }else{
            return -1;
        }
    }

    int get_sum(){
        if(mp.size()==0){
            return 0;
        }
        return sum;
    }
};


void solve(){
   int q;
   cin>>q;
   queries Q;
   while(q--){
    int t;
    cin>>t;
    if(t==1){
        int x;
        cin>>x;
        Q.add(x);
    }else if(t==2){
        int x;
        cin>>x;
        Q.remove(x);
    }else if(t==3){
        string s;
        cin>>s;
        cout<<Q.get_min()<<endl;
    }else if(t==4){
        string s;
        cin>>s;
        cout<<Q.get_max()<<endl;
    }else if(t==5){
        string s;
        cin>>s;
        cout<<Q.get_sum()<<endl;
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