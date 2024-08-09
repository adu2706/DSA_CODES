#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int n,x,y;
int arr[1000100];

bool check(int mid){
    multiset<int> mt;
    for(int i=0;i<mid;i++){
        mt.insert(arr[i]);
    }
    int sum = 0;
    int cnt = 0;
    int k = mid-y;
    for(auto x:mt){
        if(cnt<k){
            sum+=x;
        }
        cnt++;
        if(cnt==k){
            break;
        }
    }

    int l = 0;
    int r = mid;
    while(r<n){
        //remove
        auto it = mt.lower_bound(arr[l]);
        int dis = distance(mt.begin(),it);
        if(dis<=k){
            sum -= arr[l];
            mt.erase(mt.find(arr[l]));
            if(mt.size()>=k){
                sum += *it;
            }
        }else{
             mt.erase(mt.find(arr[l]));
        }
        l++;

        //add
        auto it1 = mt.lower_bound(arr[r]);
        int dis1 = distance(mt.begin(),it);
        if(dis1>k){
            mt.insert(arr[r]);
        }else{
            sum += arr[r];
            sum-= 
        }
        if(arr[r]<=*it){
            sum -= *it;
            sum += arr[r];
            mt.insert(arr[r]);
        }else{
            mt.insert(arr[r]);
        }
        r++;

        if(sum<=x){
            return 1;
        }
    }
    return 0;
}

void solve(){
   cin>>n>>x>>y;
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }

   int lo = y;
   int hi = n;
   int ans = y;
   while(lo<=hi){
    int mid = (lo+hi)/2;
    if(check(mid)==1){
        ans = mid;
        lo = mid+1;
    }else{
        hi = mid-1;
    }
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