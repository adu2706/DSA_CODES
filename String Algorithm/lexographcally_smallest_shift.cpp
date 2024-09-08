#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct Hashing {
    vector<int> fhash;
    vector<int> pk;
    int sz;
    int p;
    int mod;

    void init(string s, int _p, int _mod) {
        p = _p;
        mod = _mod;
        sz = s.length();
        fhash.resize(sz);
        pk.resize(sz);

        fhash[0] = s[0] - 'a' + 1;
        pk[0] = 1;

        for (int i = 1; i < sz; i++) {
            fhash[i] = (fhash[i - 1] * p + (s[i] - 'a' + 1)) % mod;
            pk[i] = (pk[i - 1] * p) % mod;
        }
    }

    int getHash(int l, int r) {
        if (l == 0) {
            return fhash[r];
        } else {
            return ((fhash[r] - fhash[l - 1] * pk[r - l + 1]) % mod + mod) % mod;
        }
    }
};

int n;
string s;
Hashing shash1;
Hashing shash2;


bool cmp(int i, int j){
    int lo = 1;
    int hi = n-1;

    int ans = 0;

    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(shash1.getHash(i,i+mid-1) == shash1.getHash(j,j+mid-1) && shash2.getHash(i,i+mid-1) == shash2.getHash(j,j+mid-1)){
            ans = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }

    return s[i+ans]<s[j+ans];
}

void solve(){
   cin>>s;

   n = s.length();

    s = s+s;
    shash1.init(s,37,999999937);
    shash2.init(s,29,999999931);
    vector<int> final;
    for(int i=0;i<n;i++){
        final.push_back(i);
    }
    sort(final.begin(),final.end(),cmp);
    for(auto v:final){
        cout<<v<<" ";
    }
    cout<<endl;

    
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