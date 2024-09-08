#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
#define endl '\n'
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<vector<int>> g;
vector<pair<int,int>> arr2; // arr2 for path query
vector<int> val;
vector<int> in,out;
int timer=-1;
void dfs(int node, int parent) {
    timer++;
    in[node] = timer;
    arr2.push_back({node, val[node]});
    for(auto v: g[node]) {
        if(v != parent) {
            dfs(v, node);
        }
    }
    timer++;
    out[node] = timer;
    arr2.push_back({-node, 0});
}

vector<vector<int>> par;
vector<int> dep;

void dfs_lca(int node, int parent, int depth){
    dep[node] = depth;
    par[node][0] = parent;

    for(int i=1;i<20;i++){
        par[node][i] = par[par[node][i-1]][i-1];
    }

    for(auto v:g[node]){
        if(v!=parent){
            dfs_lca(v,node,depth+1);
        }
    }
}

int lca(int u, int v){
    if(dep[u]<dep[v]){
        swap(u,v);
    }

    for(int i=19;i>=0;i--){
        if((dep[u]-dep[v])&(1<<i)){
            u = par[u][i];
        }
    }

    if(u==v){
        return u;
    }

    for(int i=19;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}


struct SegTree2 {
    //path between to node type queries
    vector<int> segT2;

    void declare(int n) {
        segT2.resize(4*n);
    }

    void build(int index, int l, int r) {
        if(l == r) {
            segT2[index] = arr2[l].second;
            return;
        }
        int mid = (l+r)/2;
        
        build(2*index, l, mid);
        build(2*index+1, mid+1, r);

        segT2[index] = max(segT2[2*index] , segT2[2*index+1]);
    }

    void update(int index, int l, int r, int pos, int val) {
        if(pos < l || pos > r) {
            return;
        }

        if(l == r) {
            arr2[l].second = val;
            segT2[index] = arr2[l].second;
            return;
        }

        int mid = (l+r)/2;
        
        update(2*index, l, mid, pos, val);
        update(2*index+1, mid+1, r, pos, val);

        segT2[index] = max(segT2[2*index] , segT2[2*index+1]);
    }

    int query(int index, int l, int r, int st, int en) {
        if(st > r || en < l) {
            return -1e18;
        }
        if(st <= l && r <= en) {
            return segT2[index];
        }

        int mid = (l+r)/2;

        return max(query(2*index, l, mid, st, en) , query(2*index+1, mid+1, r, st, en));
    }
};

void solve() {
    int n,q;
    cin >> n >>q;
    in.clear();
    out.clear();
    in.resize(n+1);
    out.resize(n+1);
    g.clear();
    g.resize(n+1);
    val.clear();
    val.resize(n+1);
    arr2.clear();
    par.clear();
    par.resize(n+1,vector<int>(21,0));
    dep.clear();
    dep.assign(n+1,0);
    for(int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);
    dfs_lca(1,0,0);

    SegTree2 st2;
    
    int m = arr2.size();
    st2.declare(m);
    st2.build(1, 0, m-1);

    while(q--) {
        int ch;
        cin >> ch;
        if(ch == 1) {
            // Update val at node x to y
            int x, y;
            cin >> x >> y;
            int inpos = in[x];
            st2.update(1, 0, m-1, inpos, y);
        } else if(ch == 2) {
            // maximum val of node between path x and node y;
            int x,y;
            cin >> x >>y;
            int inpos1 = in[x];
            int inpos2 = in[y];
            int inpos3 = in[lca(x,y)];
            int maxi1,maxi2;
            maxi1 = st2.query(1, 0, m-1, inpos3, inpos1);
            maxi2 = max(maxi1,st2.query(1, 0, m-1, inpos3,inpos2));
            cout<<maxi2<<" ";
        }
    }
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}
