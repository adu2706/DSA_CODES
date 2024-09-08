#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 10000
#define F first
#define S second

int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int dep[200200];
int par[200200];
vector<int> g[200200];

int diameter;
int cnt;

void dfs1(int node, int parent, int depth) {
    dep[node] = depth;
    par[node] = parent;
    if(dep[node]==(diameter/2 - 1)){
        cnt++;
    }
    for (auto v : g[node]) {
        if (v != parent) {
            dfs1(v, node, depth + 1);
        }
    }
}

void dfs2(int node, int parent, int depth) {
    dep[node] = depth;
    par[node] = parent;
    if(dep[node]==(diameter/2)){
        cnt++;
    }
    for (auto v : g[node]) {
        if (v != parent) {
            dfs2(v, node, depth + 1);
        }
    }
}

void dfs(int node, int parent, int depth) {
    dep[node] = depth;
    par[node] = parent;
    
    for (auto v : g[node]) {
        if (v != parent) {
            dfs(v, node, depth + 1);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    if(n==1){
        cout<<1<<endl;
        return;
    }

    // Clear previous graph data if running multiple test cases
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        dep[i] = 0;
        par[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // First DFS to find the farthest node from node 1
    dfs(1, 0, 0);
    int mach1 = 1;
    for (int i = 1; i <= n; i++) {
        if (dep[i] > dep[mach1]) {
            mach1 = i;
        }
    }

    // Second DFS to find the farthest node from mach1 (this gives us the diameter)
    dfs(mach1, 0, 0);
    int mach2 = 1;
    for (int i = 1; i <= n; i++) {
        if (dep[i] > dep[mach2]) {
            mach2 = i;
        }
    }

    vector<int> centre;
    diameter = dep[mach2];

    if (diameter % 2 == 0) {
        int node = mach2;
        int depth = 1;
        while (depth <= diameter / 2) {
            node = par[node];
            depth++;
        }
        centre.push_back(node);
        
    } else {
        int node = mach2;
        int depth = 1;
        while (depth <= diameter / 2) {
            node = par[node];
            depth++;
        }
        centre.push_back(node);
        node = mach2;
        depth = 1;
        while (depth <= diameter / 2 + 1) {
            node = par[node];
            depth++;
        }
        centre.push_back(node);
    }

    if (diameter % 2 == 0) {
        //1centre
        vector<int> v;
        int sum = 0;
        for(auto x:g[centre[0]]){
            cnt = 0;
            dfs1(x,centre[0],0);
            v.push_back(cnt);
            sum+=cnt;
        }
        
        int total_diameter = 0;
        for(int i=0;i<v.size();i++){
            total_diameter += v[i]*(sum-v[i]);
        }
        // cout<<"total diametre is : "<<total_diameter<<endl;
        cout<<total_diameter/2<<endl;
    } else {
        //2 cnetres
        int cnt1 = 0;
        int cnt2 = 0;
        cnt = 0;
        dfs2(centre[0],centre[1],0);
        cnt1 = cnt;

        cnt = 0;
        dfs2(centre[1],centre[0],0);
        cnt2 = cnt;

        int total_diameter = cnt1*cnt2;
        // cout<<"total diametre is : "<<total_diameter<<endl;
        cout<<total_diameter<<endl;
    }
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
