#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<int> last_smaller(int n, vector<int> arr){
    vector<int> ppos(n);
    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        if(!st.empty()){
            ppos[i] = st.top();
        } else {
            ppos[i] = -1;
        }
        st.push(i);
    }

    return ppos;
}

vector<int> next_smaller(int n, vector<int> arr){
    vector<int> ppos(n);
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        if(!st.empty()){
            ppos[i] = st.top();
        } else {
            ppos[i] = n;
        }
        st.push(i);
    }

    return ppos;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<int> last = last_smaller(n, arr);
    vector<int> next = next_smaller(n, arr);

    int ans = 0;
    for(int i=0;i<n;i++){
        int l = last[i];
        int r = next[i];
        ans = max(ans, arr[i] * (r - l - 1));
    }

    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
}
