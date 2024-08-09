#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<int> previous_smaller(int n, vector<int> arr){
    vector<int> ans(n);
    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }

        if(st.empty()){
            ans[i] = -1;
        }else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<int> next_smaller(int n, vector<int> arr){
    vector<int> ans(n);
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }

        if(st.empty()){
            ans[i] = n;
        }else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}


void solve(){
   int n;
   cin>>n;
   vector<int> arr(n);

   for(int i=0;i<n;i++){
    cin>>arr[i];
   }

   vector<int> left = previous_smaller(n,arr);
    vector<int> right = next_smaller(n,arr);
    

    int ans = 0;
    for(int i=0;i<n;i++){
        ans += arr[i]*(i-left[i])*(right[i]-i);
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