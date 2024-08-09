#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> arr;

bool check(int mid){
    int k = ((n*(n+1)/2)+1)/2;

    int head = -1;
    int tail = 0;
    int ans = 0;
    int sum = 0;

    while(tail<n){
        while(head+1<n && sum+arr[head+1]<=mid){
            head++;
            sum+=arr[head];
        }
        ans+=head-tail+1;
        if(head>=tail){
            sum-=arr[tail];
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }

    if(ans>=k){
        return 1;
    }else{
        return 0;
    }
}

void solve(){
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int lo = 0;
    int hi = 1e18;
    int ans = 0;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(mid)){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    cout<<ans<<endl;
    arr.clear();
}


signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}