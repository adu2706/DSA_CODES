#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
const int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

void solve(){
   int n, k;
   cin >> n >> k;
   vector<int> arr(n);
   for(int i = 0; i < n; i++){
      cin >> arr[i];
   }

   int ans = 0;
   for(int i = 29; i >= 0; i--){
      vector<int> elementbitset;
      for(auto v : arr){
         if(v & (1 << i)){
            elementbitset.push_back(v);
         }
      }
      if(elementbitset.size() >= k){
         ans += (1LL << i);
         arr = elementbitset;
      }
   }

   cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
