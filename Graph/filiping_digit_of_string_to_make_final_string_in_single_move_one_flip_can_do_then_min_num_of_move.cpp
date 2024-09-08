#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<vector<int>> g;
vector<bool> ban; 

int getVal(string s){
    reverse(s.begin(),s.end());
    int Val = 0;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            Val = Val|(1<<i);
        }
    }
    return Val;
}

void add_edge(int x, int y){
    if(!ban[x] && !ban[y]){
        g[x].push_back(y);
        g[y].push_back(x);
    }
}
vector<int> vis,dis;
void bfs(int sc){
    dis.assign((1<<20),1e18);
    vis.assign((1<<20),0);

    queue<int> q;
    dis[sc] = 0;
    q.push(sc);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(vis[cur]==1){
            continue;
        }else{
            vis[cur] = 1;
        }

        for(auto neigh:g[cur]){
            if(dis[neigh]>dis[cur]+1){
                dis[neigh] = dis[cur]+1;
                q.push(neigh);
            }
        }
    }
}

void solve(){
    string s;
    cin>>s;
    int sc =getVal(s);
    string e;
    cin>>e;
    int en = getVal(e);
    int k; // k ban string
    ban.assign((1<<20),0);
    for(int i=0;i<k;i++){
        string str;
        cin>>str;
        int x = getVal(str);
        ban[x] = 1;
    }

    g.resize(1<<20);
    for(int i=0;i<(1<<20);i++){
        for(int j=0;j<20;j++){
            add_edge(i,(i^(1<<j)));
        }
    }
    bfs(sc);
    if(dis[en]==1e18){
        cout<<"Not Possible"<<endl;
    }else{
        cout<<dis[en]<<endl;
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}