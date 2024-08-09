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
    int n;
    cin>>n;
    int arr[n];
    int cnt[21];
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<21;j++){
            if(arr[i]&(1<<j)){
                cnt[j]++;
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        int largepos = 0;
        for(int j=0;j<21;j++){
            if(cnt[j]){
                largepos|=(1<<j);
                cnt[j]--;
            }
        }
        ans += largepos*largepos;
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