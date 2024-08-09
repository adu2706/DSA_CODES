#include <bits/stdc++.h>
using namespace std;
#define int long long

map<int, int> freq;

void primefact(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                cnt++;
                x /= i;
            }
            freq[i] = cnt;
        }
    }
    if (x != 1) {
        freq[x] = 1;
    }
}

signed main() {
    while(true){
    int n, d;
    cin >> n >> d;
    if(n==0 && d==0){
        break;
    }
    freq.clear();
    primefact(n);
    if (freq.find(2) != freq.end()) {
        freq[2] += d;
    } else {
        freq[2] = d;
    }

    if (freq.find(5) != freq.end()) {
        freq[5] += d;
    } else {
        freq[5] = d;
    }

    for (auto &x : freq) {
        x.second *= 2;
    }

    int mod = 1000007;
    int ans = 2;
    for (auto &x : freq) {
        ans = (ans % mod * (1 + x.second) % mod) % mod;
    }

    cout << ans-1 << endl;
    }
    
}
