#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct Node {
    int child[26];
    vector<string> matching;

    Node() {
        matching.clear();
        memset(child, -1, sizeof(child));
    }
};

struct Tries {
    vector<Node> nodes;

    Tries() {
        Node rootnode;
        nodes.push_back(rootnode);
    }

    void insert(string s) {
        int cur_node_idx = 0;
        for (int i = 0; i < s.length(); i++) {
            if (nodes[cur_node_idx].child[s[i] - 'a'] == -1) {
                Node new_node;
                nodes.push_back(new_node);
                nodes[cur_node_idx].child[s[i] - 'a'] = nodes.size() - 1;
            }
            cur_node_idx = nodes[cur_node_idx].child[s[i] - 'a'];
        }
        nodes[cur_node_idx].matching.push_back(s);
    }

    vector<string> result;

    void dfs(string s, int k, int node, int pos) {
        if (k < 0) {
            return;
        }

        if (pos == s.length()) {
            for (auto v : nodes[node].matching) {
                result.push_back(v);
            }
            return;
        }

        for (int i = 0; i < 26; i++) {
            if (nodes[node].child[i] != -1) {
                dfs(s, k - (i != (s[pos] - 'a')), nodes[node].child[i], pos + 1);
            }
        }
    }

    void query(string s, int k) {
        result.clear();
        dfs(s, k, 0, 0);
        for (auto v : result) {
            cout << v << " ";
        }
        cout << endl;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<string> str(n);
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    sort(str.begin(), str.end());

    Tries tt;
    for (auto v : str) {
        tt.insert(v);
    }

    while (q--) {
        string s;
        int k;
        cin >> s >> k;
        tt.query(s, k);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
