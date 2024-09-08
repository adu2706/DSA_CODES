#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

set<string> all_pos;

void generate(string s, int k){
    if(k==0){
        all_pos.insert(s);
        return;
    }

    for(int i=0;i<s.length();i++){
        for(int j=i;j<s.length();j++){
            string temp = s;
            reverse(temp.begin()+i,temp.begin()+j+1);
            generate(temp,k-1);
        }
    }
}

void solve(){
   string s,t;
   cin>>s>>t;

   all_pos.clear();
   generate(s,2);
   set<string> s1 = all_pos;

   all_pos.clear();
   generate(t,2);
   set<string> s2 = all_pos;

    bool flag = 0;
   for(auto v:s1){
    if(s2.find(v)!=s2.end()){
        flag = 1;
        break;
    }
   }

   if(flag){
    cout<<"YES"<<endl;
   }else{
    cout<<"NO"<<endl;
   }

    
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