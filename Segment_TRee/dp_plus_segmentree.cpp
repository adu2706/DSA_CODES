#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int n,D,arr[200200];

map<int,int> compVal;

int t[400400];

void  update(int index, int l, int r, int pos, int val){
    if(pos<l || pos>r){
        return;
    }

    if(l==r){
        t[index] = max(t[index],val);
        return;
    }

    int mid = (l+r)/2;

    update(2*index,l,mid,pos,val);
    update(2*index+1,mid+1,r,pos,val);

    t[index] = max(t[2*index],t[2*index+1]);
}

int query(int index, int l, int r, int lq, int rq){
    if(rq<l || lq>r){
        return 0;
    }

    if(lq<=l && r<=rq){
       return t[index];
    }

    int mid = (l+r)/2;

    return max(query(2*index,l,mid,lq,rq),query(2*index+1,mid+1,r,lq,rq));
}


void solve(){
   cin>>n;
   for(int i=0;i<n;i++){
    cin>>arr[i];
    compVal[arr[i]];
   }
    cin>>D;
   int cnt = 0;
   for(auto &v:compVal){
    v.second = cnt++;
   } 
   
   int dp[n];
    int ans = 0;
   for(int i=0;i<n;i++){
    int lo = arr[i]-D;
    int hi = arr[i]+D;

    auto it = compVal.upper_bound(hi);
    it--;
    hi = it->second;

    it = compVal.lower_bound(lo);
    lo = it->second;

    dp[i] = query(1,0,cnt-1,lo,hi)+1;
    ans = max(ans,dp[i]);
    update(1,0,cnt-1,compVal[arr[i]],dp[i]);
   }

   cout<<ans<<endl;
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