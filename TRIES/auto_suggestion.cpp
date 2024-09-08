#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct node{
    int child[26];
    int end_count;
    int proper_prefix_cnt;
    vector<int> matching;
    node(){
        memset(child, -1, sizeof(child));
        end_count = 0;
        proper_prefix_cnt = 0;
    }
};

struct trie{
    vector<node> nodes;
    trie(){
        node rootnode;
        nodes.push_back(rootnode);
    }

    void insert(string s, int idx){
        int cur_node_idx = 0;
        for(int i = 0; i < s.length(); i++){
            if(nodes[cur_node_idx].child[s[i] - 'a'] == -1){
                node new_node;
                nodes.push_back(new_node);
                nodes[cur_node_idx].child[s[i] - 'a'] = nodes.size() - 1;
            }
            nodes[cur_node_idx].proper_prefix_cnt++;
            if(nodes[cur_node_idx].matching.size() < 10001){
                nodes[cur_node_idx].matching.push_back(idx);
            }
            cur_node_idx = nodes[cur_node_idx].child[s[i] - 'a'];
        }
        if(nodes[cur_node_idx].matching.size() < 10001){
            nodes[cur_node_idx].matching.push_back(idx);
        }
        nodes[cur_node_idx].end_count++;
    }

    void query(string s, vector<string> &text, int k){
        int cur_node_idx = 0;
        for(int i = 0; i < s.length(); i++){
            if(nodes[cur_node_idx].child[s[i] - 'a'] == -1){
                cout<<" "<<endl;
                return;
            }
            cur_node_idx = nodes[cur_node_idx].child[s[i] - 'a'];
        }
        int cnt = 0;
        for(auto idx : nodes[cur_node_idx].matching){
            cout << text[idx] << " ";
            cnt++;
            if(cnt == k){
                break;
            }
        }
        cout << endl;
    }

    int get_node_count(){
        return nodes.size();
    }
};

void solve(){
    int n, maxl, q;
    cin >> n >> maxl >> q;

    trie tt;
    vector<string> text(n);
    for(int i = 0; i < n; i++){
        int l;
        cin >> l >> text[i];
    }
    sort(text.begin(), text.end());
    for(int i = 0; i < n; i++){
        tt.insert(text[i], i);
    }
    while(q--){
        int l, k;
        string s_query;
        cin >> l >> s_query >> k;
        for(int i=0;i<s_query.length();i++){
            tt.query(s_query.substr(0,i+1), text, k);
        }
        
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
