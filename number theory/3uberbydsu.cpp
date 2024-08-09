#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int par[100100];
int size[100100];


int find(int x){
    if(par[x]==x){
        return x;
    } else {
        return (par[x] = find(par[x]));
    }
}


void unite(int x, int y){
    int rootx = find(x);
    int rooty = find(y);
    if(rootx != rooty){
        if(size[rootx] < size[rooty]){
            swap(rootx, rooty); 
        }
        size[rootx] += size[rooty];
        par[rooty] = rootx;
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < 26 + n; i++){
        par[i] = i;
        size[i] = 1;
    }
    
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int i = 0; i < n; i++){
        for(char ch : v[i]){
            int char_idx = ch - 'a';
            unite(i + 26, char_idx);
        }
    }

    set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(find(i + 26));
    }
    cout << s.size() << endl;
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
