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
int n,T;
cin>>n>>T;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}

sort(arr,arr+n);

int ans = 0;
for(int j=1;j<=n-2;j++){
    int i = 0;
    int k = n-1;
    while(i<j && j<k){
        int sum = arr[i]+arr[j]+arr[k];
        if(sum==T){
                int tempi = i;
                int tempk = k;
                while(tempi<j && arr[i]==arr[tempi]){
                    tempi++;
                }

                while(tempk>j && arr[k]==arr[tempk]){
                    tempk--;
                }

                ans+=(tempi-i)*(k-tempk);

        }else if(sum>T){
            k--;
        }else if(sum<T){
            i++;
        }
    }
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
