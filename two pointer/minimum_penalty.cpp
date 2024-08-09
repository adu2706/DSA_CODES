#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
vector<int> freq(1000100);
void solve(){
   int n, d;
   cin >> n >> d;
   vector<int> arr(n);
   for(int i = 0; i < n; i++){
       cin >> arr[i];
   }

   
   int ans = LLONG_MAX;
   int head = -1;
   int tail = 0;
   int distinctcnt = 0;
   int len = 0;

   while(tail < n){
       while(head + 1 < n && (len < d)){
            len++;
           head++;
           if(freq[arr[head]] == 0){
               distinctcnt++;
           }
           freq[arr[head]]++;
       }
       if (head - tail + 1 == d) {
           ans = min(ans, distinctcnt);
       }
       if(head >= tail){
           freq[arr[tail]]--;
           if(freq[arr[tail]] == 0){
               distinctcnt--;
           }
           tail++;
           len--;
       } else {
            len=0;
           tail++;
           head = tail - 1;
       }
   }

   cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}