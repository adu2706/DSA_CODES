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
    int child[2];
    Node(){
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
            int x = (n&(1LL<<i))?1:0;
            if(nodes[cur_node_idx].child[x]==-1){
                Node new_node;
                nodes.push_back(new_node);
                nodes[cur_node_idx].child[x] = nodes.size()-1;
            }
            cur_node_idx = nodes[cur_node_idx].child[x];
        }
    }

    int findMaxXor(int n){
        int cur_node_idx = 0;
        int ans = 0;
        for(int i=31;i>=0;i--){
            int x = (n&(1LL<<i))?1:0;
            if(nodes[cur_node_idx].child[x^1]!=-1 ){
                ans |= (1LL<<i);
                cur_node_idx = nodes[cur_node_idx].child[x^1];
            }else{
                cur_node_idx = nodes[cur_node_idx].child[x];
            }
        }
        return ans;
    }
};

void solve(){
   int n;
   cin>>n;
   vector<int> arr(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }

   Tries tt;
   tt.insert(0);
   int Xor = 0;
   int ans = 0;
   for(int i=0;i<n;i++){
    Xor = Xor^arr[i];
    ans = max(ans,tt.findMaxXor(Xor));
    tt.insert(Xor);
   }
    cout<<ans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}