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
   int n,q;
   cin>>n>>q;
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
    sort(arr,arr+n);
   while(q--){
    int t,x;
    cin>>t>>x;
    if(t==1){
        auto it = lower_bound(arr,arr+n,x);
        if(it!=arr+n){
            cout<<*lower_bound(arr,arr+n,x)<<" ";
        }else {
            cout<<-1<<" ";
        }    
    }else if(t==2){
        auto it = upper_bound(arr,arr+n,x);
        if(it!=arr+n){
            cout<<*upper_bound(arr,arr+n,x)<<" ";
        }else {
            cout<<-1<<" ";
        }
    }else if(t==3){
        auto it = upper_bound(arr,arr+n,x)-arr;
        cout<<it<<" ";
    }else if(t==4){
        auto it = lower_bound(arr,arr+n,x)-arr;
        cout<<it<<" ";
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