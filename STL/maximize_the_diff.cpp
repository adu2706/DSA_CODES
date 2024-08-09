#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

bool comp(const pair<int,int> &a, const pair<int,int> &b){
    return a.F+a.S > b.F+b.S;
}


void solve(){
   int n;
   cin>>n;
   vector<pair<int,int>> cards(n);
   for(int i=0;i<n;i++){
    cin>>cards[i].F>>cards[i].S;
   }
   sort(cards.begin(),cards.end(),comp);
    cout<<cards[n-1].F+cards[n-1].S<<endl;
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