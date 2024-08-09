#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1000100;

int sp[MAXN];

// Function to calculate the smallest prime factor for each number
void computeSmallestPrimeFactors() {
    for (int i = 2; i < MAXN; i++) {
        sp[i] = i;
    }
    for (int i = 2; i * i < MAXN; i++) {
        if (sp[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (sp[j] == j) {
                    sp[j] = i;
                }
            }
        }
    }
}

// Function to get the prime factors of a number
vector<int> primeFactors(int x) {
    vector<int> ans;
    while (x > 1) {
        ans.push_back(sp[x]);
        x = x / sp[x];
    }
    return ans;
}

// Function to solve the problem
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    computeSmallestPrimeFactors();

    map<vector<pair<int, int>>, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> temp = primeFactors(arr[i]);
        map<int, int> tempmp;
        for (auto v : temp) {
            tempmp[v]++;
        }
        vector<pair<int, int>> ins, check;
        for (auto v : tempmp) {
            if (v.second % 3 != 0) {
                ins.push_back({v.first, v.second % 3});
                check.push_back({v.first, 3 - v.second % 3});
            }
        }
        ans += mp[check];
        mp[ins]++;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
