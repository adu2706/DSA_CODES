#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


vector<int> generate(vector<int> arr){
    int n = arr.size();
    vector<int> subVals;
    for(int mask = 0; mask < (1 << n); mask++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            if((mask & (1 << j))){
                sum += arr[j];
            }
        }
        subVals.push_back(sum);
    }
    sort(subVals.begin(), subVals.end());
    return subVals;
}

void solve(){
    int n, x;
    cin >> n >> x;
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
    
    int total_num = 0;
    for(int i = 0; i < subVal1.size(); i++){
        auto it = upper_bound(subVal2.begin(), subVal2.end(), x - subVal1[i]);
        total_num += distance(subVal2.begin(), it);
    }

    cout << total_num << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
