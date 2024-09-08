#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<vector<pair<int,int>>> g;
vector<vector<int>> dp;
int n,k;
void dfs(int node, int par){
    //dp[node][take]
    // take == 0 (merge node with parent) and then take k-1 merge from child
    // take ==1 (not merge node with parent) and then take k merge from child

    //set default like leaf node
    dp[node][0] = 0; //node already merge with parent and node is leaf so no merge it can take further so value added is zero
    dp[node][1] = 0; //node not erge with parent and node is leaf so no merge it can take further so value added is zero
    vector<int> delta;
    int base = 0;
    for(auto v:g[node]){
        int child = v.first;
        int weight = v.second;
        if(child!=par){
            dfs(child,node);
            base += dp[child][1]; //child not merge with node;
            delta.push_back(-dp[child][1]+weight+dp[child][0]); //what if we choose to merge the child with its parent node then we have to substract the not merging senario with its parent and the add weight and merging case 
        }
    }

    sort(delta.begin(),delta.end());
    delta.push_back(0); //if we want to not select any of them 
    reverse(delta.begin(),delta.end());

    for(int ch=0;ch<(int)delta.size();ch++){
        //ch==0 means not take any node 
        //we first sort the delta the append '0' in last which means not taking any node
        //after that reverse the delta vector
        //'0' comes first in delta vector
        //so first choise is always not taking any node
        // and then we have to take at max k child
        base += delta[ch];
        dp[node][1] = max(dp[node][1],base);
        if(ch==k){
            // total k choice plus one choice which is not taking any child is done
            break;
        }
        if(ch<=k-1){
            // already taken one merge of node with parent so we have to take only at max k-1 child
            dp[node][0] = max(dp[node][0],base);
        }
    }
}

void solve(){
    cin>>n>>k;
    g.clear();
    g.resize(n+1);
    dp.clear();
    dp.resize(n+1,vector<int>(2,0));

    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    dfs(1,0);
    cout<<max(dp[1][0],dp[1][1])<<endl;
    
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