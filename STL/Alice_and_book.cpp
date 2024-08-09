#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define endl '\n'
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
   
    multiset<int> mt;
    int b = 1;
    for(int i=0;i<n;i++){
        if(arr[i]>=b){
            mt.insert(arr[i]);
        }

        while(!mt.empty() && *mt.begin()<=b){
            mt.erase(mt.begin());
        }

        if(mt.size()>b){
            b++;
        }
        cout<<b<<" ";
    }
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
