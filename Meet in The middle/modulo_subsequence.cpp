#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int n, m;

vector<int> generate(vector<int> arr){
    int n = arr.size();
    vector<int> subVals;
    for(int mask = 0; mask < (1 << n); mask++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            if((mask & (1 << j))){
                (sum += arr[j])%=m;
            }
        }
        subVals.push_back(sum%m);
    }
    sort(subVals.begin(), subVals.end());
    return subVals;
}

void solve(){
    cin >> n >> m;
    vector<int> arr1, arr2;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        if(i < (n / 2)){
            arr1.push_back(c);
        }else{
            arr2.push_back(c);
        }
    }

    vector<int> subVal1 = generate(arr1);
    vector<int> subVal2 = generate(arr2);
    
    int maxi = 0;
    for(int i = 0; i < subVal1.size(); i++){
        auto it = upper_bound(subVal2.begin(), subVal2.end(), m-1- subVal1[i]);
        it--;
        int val = *it;
        val += subVal1[i];
        maxi = max(maxi,val);
    }

    cout << maxi << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
