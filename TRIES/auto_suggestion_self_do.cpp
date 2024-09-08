#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<string> all_str;
struct Node{
    int child[26];
    vector<int> matching;

    Node(){
        matching.clear();
        memset(child,-1,sizeof(child));
    }
};

struct Tries{
    vector<Node> nodes;

    Tries(){
        Node rootnode;
        nodes.push_back(rootnode);
    } 

    void insert(string s, int str_idx){
        int cur_node_idx = 0;
        for(int i=0;i<s.length();i++){
            if(nodes[cur_node_idx].child[s[i]-'a']==-1){
                Node new_node;
                nodes.push_back(new_node);
                nodes[cur_node_idx].child[s[i]-'a']  = nodes.size()-1;
            }
            nodes[cur_node_idx].matching.push_back(str_idx);
            cur_node_idx  = nodes[cur_node_idx].child[s[i]-'a'];
        }
        nodes[cur_node_idx].matching.push_back(str_idx);
    }

    void query(string s, int k){
        int cur_node_idx = 0;
        for(int i=0;i<s.length();i++){
            if(nodes[cur_node_idx].child[s[i]-'a']==-1){
               cout<<endl;
               return;
            }
            cur_node_idx  = nodes[cur_node_idx].child[s[i]-'a'];
        }

        for(int i=0;i<min(k,(int)nodes[cur_node_idx].matching.size());i++){
            cout<<all_str[nodes[cur_node_idx].matching[i]]<<" ";
        }
        cout<<endl;
    }
};


void solve(){
   int n,maxlen,q;
   cin>>n>>maxlen>>q;
    all_str.resize(n);
   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    cin>>all_str[i];
   }

   sort(all_str.begin(),all_str.end());

    Tries tt;
   for(int i=0;i<n;i++){
    tt.insert(all_str[i],i);
   }

   while(q--){
    int x;
    cin>>x;
    string s;
    cin>>s;
    int k;
    cin>>k;
    for(int i=0;i<s.length();i++){
        tt.query(s.substr(0,i+1),k);
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