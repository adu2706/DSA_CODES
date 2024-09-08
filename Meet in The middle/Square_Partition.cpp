#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

set<vector<int>> all_sol;

void generate(int level, int a, int b, int c, int d, vector<int>& arr){
    if(level == arr.size()){
        all_sol.insert({a, b, c, d});
        return;
    }
    generate(level + 1, a + arr[level], b, c, d, arr);
    generate(level + 1, a, b + arr[level], c, d, arr);
    generate(level + 1, a, b, c + arr[level], d, arr);
    generate(level + 1, a, b, c, d + arr[level], arr);
}

void solve(){
    int n, total_sum = 0;
    cin >> n;
    vector<int> arr1, arr2;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        total_sum += x;
        if(i < n / 2){
            arr1.push_back(x);
        } else {
            arr2.push_back(x);
        }
    }

    if(total_sum % 4 != 0){
        cout << "No" << endl;
        return;
    }

    set<vector<int>> pos1, pos2;

    all_sol.clear();
    generate(0, 0, 0, 0, 0, arr1);
    pos1 = all_sol;

    all_sol.clear();
    generate(0, 0, 0, 0, 0, arr2);
    pos2 = all_sol;

    bool flag = false;
    for(auto &v : pos1){
        int p, q, r, s;
        p = (total_sum / 4) - v[0];
        q = (total_sum / 4) - v[1];
        r = (total_sum / 4) - v[2];
        s = (total_sum / 4) - v[3];
        vector<int> x = {p, q, r, s};
        if(pos2.find(x) != pos2.end()){
            flag = true;
            break;
        }
    }

    if(flag){
        // possible to make square using all the stick
        cout << "Yes" << endl;
    } else {
        // not possible
        cout << "No" << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
}
