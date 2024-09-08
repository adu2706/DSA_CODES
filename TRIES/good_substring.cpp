#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int k;
vector<int> is_good;
struct TrieNode {
    int children[26];
    int bad_count;
    TrieNode() {
        bad_count = 0;
        memset(children,-1,sizeof(children));
    }
};

struct Trie {
    vector<TrieNode> nodes;
    
    Trie(){
        nodes.push_back(TrieNode());
    }

    void insert(string s) {
        int cur_node = 0;
        int bad_count = 0;

        for (char c : s) {
            int idx = c - 'a';
            bad_count += (is_good[idx] == 0);
            if (bad_count > k) break;
            
            if (nodes[cur_node].children[idx] == -1) {
                nodes.push_back(TrieNode());
                nodes[cur_node].children[idx] = nodes.size()-1;
            }
            
            cur_node = nodes[cur_node].children[idx];
        }
    }

    int count_distinct_good_substrings() {
        return nodes.size();
    }
};

void solve() {
    string s;
    cin >> s;

    string binarys;
    cin >> binarys;
    cin >> k;
    is_good.resize(26);
    for (int i = 0; i < 26; i++) {
        is_good[i] = binarys[i] - '0';
    }

    Trie trie;

    for (int i = 0; i < s.length(); i++) {
        trie.insert(s.substr(i));
    }

    int result = trie.count_distinct_good_substrings();
    cout << result-1 << endl;
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