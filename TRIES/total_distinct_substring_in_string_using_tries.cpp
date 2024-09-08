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
    node(){
        memset(child,-1,sizeof(child));
    }
};

struct trie{
    vector<node> nodes;
    trie(){
        node rootnode;
        //fill for root node
        nodes.push_back(rootnode);
    }

    void insert(string s){
        int cur_node_idx=0; //rootnode in starting
        for(int i=0;i<s.length();i++){
            if(nodes[cur_node_idx].child[s[i]-'a']==-1){
                node new_node;
                nodes.push_back(new_node);
                nodes[cur_node_idx].child[s[i]-'a'] = nodes.size()-1;
            }
            cur_node_idx = nodes[cur_node_idx].child[s[i]-'a'];
        }
    }

    int get_node_count(){
        return nodes.size();
    }
};


void solve(){
   string s;
   cin>>s;

   trie t;

   for(int i=0;i<s.length();i++){
    t.insert(s.substr(i));
   }

   cout<<t.get_node_count()-1<<endl;
    
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