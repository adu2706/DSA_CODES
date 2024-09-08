#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct Node{
    int cnt;
    int child[26];

    Node(){
        cnt = 0;
        memset(child,-1,sizeof(child));
    }
};


struct Tries{
    vector<Node> nodes;

    Tries(){
        nodes.push_back(Node());
    }

    void insert(int n){
        int cur_node_idx = 0;
        for(int i=31;i>=0;i--){
            int x = (n&(1LL<<i))?1:0;
            nodes[cur_node_idx].cnt++;
            if(nodes[cur_node_idx].child[x]==-1){
                nodes.push_back(Node());
                nodes[cur_node_idx].child[x] = nodes.size()-1;
            }
            cur_node_idx = nodes[cur_node_idx].child[x];
        }
        nodes[cur_node_idx].cnt++;
    }

    void del(int n){
        int cur_node_idx = 0;
        for(int i=31;i>=0;i--){
            int x = (n&(1LL<<i))?1:0;
            if(nodes[cur_node_idx].cnt>0){
                nodes[cur_node_idx].cnt--;
            }

            if(nodes[cur_node_idx].cnt==0){
                nodes[cur_node_idx].child[x] = -1;
            }
            cur_node_idx = nodes[cur_node_idx].child[x];
        }
        if(nodes[cur_node_idx].cnt>0){
            nodes[cur_node_idx].cnt--;
        }
    }

    void find_total(int _y, int _k){
        int ans = 0;
        int cur_node_idx = 0;
        for(int i=31;i>=0;i--){
            int y = (_y & (1LL << i)) ? 1 : 0;
            int k = (_k & (1LL << i)) ? 1 : 0;
            if(y == 0 && k == 0){
                if(nodes[cur_node_idx].child[0] != -1){
                    cur_node_idx = nodes[cur_node_idx].child[0];
                } else {
                    break;
                }
            } else if(y == 1 && k == 0){
                if(nodes[cur_node_idx].child[1] != -1){
                    cur_node_idx = nodes[cur_node_idx].child[1];
                } else {
                    break;
                }
            } else if(y == 0 && k == 1){
                if(nodes[cur_node_idx].child[0] != -1){
                    ans += nodes[nodes[cur_node_idx].child[0]].cnt;
                }
                if(nodes[cur_node_idx].child[1] != -1){
                    cur_node_idx = nodes[cur_node_idx].child[1];
                } else {
                    break;
                }
            } else if(y == 1 && k == 1){
                if(nodes[cur_node_idx].child[1] != -1){
                    ans += nodes[nodes[cur_node_idx].child[1]].cnt;
                }
                if(nodes[cur_node_idx].child[0] != -1){
                    cur_node_idx = nodes[cur_node_idx].child[0];
                } else {
                    break;
                }
            }
        }
        cout << ans << endl;
    }
};

void solve(){
    int q;
    cin >> q;
    Tries tt;
    tt.insert(0);
    while(q--){
        char ch;
        cin >> ch;
        if(ch == '+'){
            int x;
            cin >> x;
            tt.insert(x);
        } else if(ch == '-'){
            int x;
            cin >> x;
            tt.del(x);
        } else if(ch == '?'){
            int y, k;
            cin >> y >> k;
            tt.find_total(y, k);
        }
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