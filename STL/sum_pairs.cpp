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
    map<int,int> freq;
    vector<int> v;
    vector<int> u;
    bag(vector<int> b,vector<int> a){
        v = b;
        u = a;
        for(int i=0;i<b.size();i++){
            freq[b[i]]++;
        }
    }

    void add(int idx, int val){
        freq[v[idx]]--;
        freq[v[idx]+val]++;
        v[idx]+=val;
    }

    int count(int tot){
        int ans = 0;
        for(int i=0;i<u.size();i++){
            if(freq.find(tot-u[i])!=freq.end()){
                ans += freq[tot-u[i]];
            }
        }
        return ans;
    }
};


void solve(){
   int n,m,q;
   cin>>n>>m>>q;
   vector<int>a(n),b(m);
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   for(int i=0;i<m;i++){
    cin>>b[i];
   }

   bag bg(b,a);
    

    while(q--){
        string s;
        cin>>s;
        if(s=="add"){
            int idx,val;
            cin>>idx>>val;
            bg.add(idx,val);
        }else{
            int tot;
            cin>>tot;
            cout<<bg.count(tot)<<endl;
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