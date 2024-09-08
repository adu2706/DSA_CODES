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
    node(){
        memset(child,-1,sizeof(child));
        end_count = 0;
        proper_prefix_cnt = 0;
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
            //process this node before going to child  
            nodes[cur_node_idx].proper_prefix_cnt++;
            cur_node_idx = nodes[cur_node_idx].child[s[i]-'a'];
        }
        //end string
        nodes[cur_node_idx].end_count++;
    }

    void query(string s){
        int cur_node_idx=0; 
        for(int i=0;i<s.length();i++){
            if(nodes[cur_node_idx].child[s[i]-'a']==-1){
               cout<<0<<endl;
               return;
            }
            cur_node_idx = nodes[cur_node_idx].child[s[i]-'a'];
        }
        cout<<nodes[cur_node_idx].end_count<<" "<<nodes[cur_node_idx].proper_prefix_cnt<<endl;
    }

    int get_node_count(){
        return nodes.size();
    }
};


void solve(){
   int n;
   cin>>n;

   trie tt;

   for(int i=0;i<n;i++){
    string s;
    cin>>s;
    tt.insert(s);
   }

   int q;
   cin>>q;
   while(q--){
    string s_query;
    cin>>s_query;
    tt.query(s_query);
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