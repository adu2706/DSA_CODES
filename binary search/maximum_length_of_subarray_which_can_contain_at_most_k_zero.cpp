#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


int n,k;
vector<int> arr,prefix;

bool check(int start, int mid){
    int sum;
    if(start==0){
        sum = prefix[mid];
    }else{
        sum = prefix[mid]-prefix[start-1];
    }

    int len = mid-start+1;
    int zero = len-sum;
    if(k>=zero){
        return 1;
    }else{
        return 0;
    }
}

void solve(){
   cin>>n>>k;
   arr.resize(n);
   prefix.resize(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
    
    prefix[0] = arr[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]+arr[i];
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        int start = i;
        int lo = i;
        int hi = n-1;
        int temp=start-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(start,mid)){
                temp = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        ans = max(ans,abs(temp-start+1));
    }
    cout<<ans<<endl;
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