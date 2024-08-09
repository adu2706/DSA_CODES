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
    int a, b;
    cin >> a >> b;
    int n = sqrt(b) + 1;
    vector<int> is_prime1(n, 1);

    for(int i = 2; i * i < n; i++){
        if(is_prime1[i] == 1){
            for(int j = i * i; j < n; j += i){
                is_prime1[j] = 0;
            }
        }
    }

    vector<int> prime;
    for(int i = 2; i < n; i++){
        if(is_prime1[i]){
            prime.push_back(i);
        }
    }

    vector<int> is_prime(b - a + 1, 1);

    for(auto v : prime){
        int curMul = max(v * v, ((a + v - 1) / v) * v);
        for(int j = curMul; j <= b; j += v){
            if(j != v){
                is_prime[j - a] = 0;
            }
        }
    }

    for(int i = 0; i < b - a + 1; i++){
        if(is_prime[i] && (i + a) > 1){
            cout << (i + a) <<" ";
        }
    }
    cout<<endl;
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
    return 0;
}
