#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second

struct Node{
    int child[2];
    int cnt;

    Node(){
        cnt = 0;
        memset(child,-1,sizeof(child));
    }
};

struct Tries{
    vector<Node> nodes;

    Tries(){
        Node root_node;
        nodes.push_back(root_node);
    }

    void insert(int n){
        int cur_node_idx = 0;
        for(int i=31;i>=0;i--){
            int x = (n & (1LL << i)) ? 1 : 0;
            nodes[cur_node_idx].cnt++;
            if(nodes[cur_node_idx].child[x] == -1){
                Node new_node;
                nodes.push_back(new_node);
                nodes[cur_node_idx].child[x] = nodes.size() - 1;
            }
            cur_node_idx = nodes[cur_node_idx].child[x];
        }
        nodes[cur_node_idx].cnt++;
    }

    void del(int n){
        int cur_node_idx = 0;
        for(int i=31;i>=0;i--){
            int x = (n & (1LL << i)) ? 1 : 0;
            if(nodes[cur_node_idx].cnt>0){
                nodes[cur_node_idx].cnt--;
            }
            if(nodes[cur_node_idx].cnt == 0){
                nodes[cur_node_idx].child[x] = -1;
                return;
            }
            cur_node_idx = nodes[cur_node_idx].child[x];
        }
        if(nodes[cur_node_idx].cnt>0){
            nodes[cur_node_idx].cnt--;
        }
    }

    void query(int n){
        int cur_node_idx = 0;
        int ans = 0;
        for(int i=31;i>=0;i--){
            int x = (n & (1LL << i)) ? 1 : 0;
            if(nodes[cur_node_idx].child[1^x] != -1 && nodes[nodes[cur_node_idx].child[1^x]].cnt > 0){
                ans |= (1LL << i);
                cur_node_idx = nodes[cur_node_idx].child[1^x];
            }else{
                cur_node_idx = nodes[cur_node_idx].child[x];
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
        int x;
        cin >> x;
        if(ch == '+'){
            tt.insert(x);
        }else if(ch == '-'){
            tt.del(x);
        }else{
            tt.query(x);
        }
   }
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
}
