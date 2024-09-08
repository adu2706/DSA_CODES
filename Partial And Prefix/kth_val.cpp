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
   int n,m,q;
   cin>>n>>m>>q;

   vector<int> arr(n+1);
   for(int i=1;i<=n;i++){
    cin>>arr[i];
   }

   vector<int> pref(n+1,0);
    while(m--){
        int l,r;
        cin>>l>>r;
        pref[l]++;
        if(r+1<=n){
            pref[r+1]--;
        }
    }

    for(int i=1;i<=n;i++){
        pref[i] += pref[i-1];
    }
    vector<pair<int,int>> ps;
    for(int i=1;i<=n;i++){
        ps.push_back({arr[i],pref[i]});
    }

    sort(ps.begin(),ps.end());

    vector<int> a(n),cnt(n);
    for(int i=0;i<n;i++){
        a[i] = ps[i].F;
        cnt[i] = ps[i].S;
    }

    for(int i=1;i<n;i++){
        cnt[i]+=cnt[i-1];
    }

    while(q--){
        int k;
        cin>>k;
        auto it = upper_bound(cnt.begin(),cnt.end(),k);
        if(it==cnt.end()){
            it--;
            if(*it!=k){
                cout<<-1<<" ";
            }else{
                cout<<a[n-1]<<" ";
            }
        }else{
            auto it1 = it-1;
            if(*it1==k){
                cout<<a[it1-cnt.begin()]<<" ";
            }else{
                cout<<a[it-cnt.begin()]<<" ";
            }
        }
    }
    cout<<endl;
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