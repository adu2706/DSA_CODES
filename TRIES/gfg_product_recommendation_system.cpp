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

    void insert(string s, int idx){
        int cur_node_idx=0; //rootnode in starting
        for(int i=0;i<s.length();i++){
            if(nodes[cur_node_idx].child[s[i]-'a']==-1){
                node new_node;
                nodes.push_back(new_node);
                nodes[cur_node_idx].child[s[i]-'a'] = nodes.size()-1;
            }
            //process this node before going to child  
            nodes[cur_node_idx].proper_prefix_cnt++;
            if(nodes[cur_node_idx].matching.size()<3){
                nodes[cur_node_idx].matching.push_back(idx);
            }
            cur_node_idx = nodes[cur_node_idx].child[s[i]-'a'];
        }
        //end string
        if(nodes[cur_node_idx].matching.size()<3){
            nodes[cur_node_idx].matching.push_back(idx);
        }
        nodes[cur_node_idx].end_count++;
    }

    // void dfs(int node_idx , string &cur_string){
    //     if(nodes[node_idx].end_count){
    //         cout<<cur_string<<endl;
    //     }
    //     for(int i=0;i<26;i++){
    //         if(nodes[node_idx].child[i]!=-1){
    //             cur_string+=char('a'+i);
    //             dfs(nodes[node_idx].child[i],cur_string);
    //             cur_string.pop_back();
    //         }
    //     }
    // }

    void query(string s, vector<string> text){
        int cur_node_idx=0; 
        for(int i=0;i<s.length();i++){
            if(nodes[cur_node_idx].child[s[i]-'a']==-1){
               cout<<0<<endl;
               return;
            }
            cur_node_idx = nodes[cur_node_idx].child[s[i]-'a'];
        }
        cout<<nodes[cur_node_idx].end_count+nodes[cur_node_idx].proper_prefix_cnt<<endl;
        // dfs(cur_node_idx,s);
        for(auto idx:nodes[cur_node_idx].matching){
            cout<<text[idx]<<" ";
        }
        cout<<endl;
    }

    int get_node_count(){
        return nodes.size();
    }
};


void solve(){
   int n;
   cin>>n;

   trie tt;
    vector<string> text;
   for(int i=0;i<n;i++){
    string s;
    cin>>s;
    text.push_back(s);
   }
    sort(text.begin(),text.end());
   for(int i=0;i<n;i++){
    tt.insert(text[0],i);
   }

   int q;
   cin>>q;
   while(q--){
    string s_query;
    cin>>s_query;
    tt.query(s_query,text);
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