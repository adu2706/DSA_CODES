#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

// Function to compute the KMP prefix table
vector<int> KMP(string &s, int n) {
    vector<int> kmp(n + 1);
    kmp[0] = -1;

    int i = 0;
    int j = -1;
    while (i < n) {
        while (j != -1 && s[i] != s[j]) {
            j = kmp[j];
        }
        j++;
        i++;
        kmp[i] = j;
    }
    return kmp;
}

void solve(int t) {
    int n;
    cin>>n;
    string s;
    cin >> s;
    

    vector<int> kmp = KMP(s, n);

    cout << "Test case #" << t << endl;
    for (int i = 2; i <= n; i++) {
        int x = i - kmp[i];
        if (kmp[i]!=0 && i % x == 0) {
            cout << i << " " << i/x << endl;
        }
    }
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    int i = 1;
    while (t--) {
        solve(i);
        i++;
    }
}
