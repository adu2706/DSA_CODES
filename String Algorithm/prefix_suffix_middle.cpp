#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<int> KMP(string &s, int n){
    vector<int> kmp(n+1);
    kmp[0] = -1;

    int i=0,j=-1;
    while(i<n){
        while(j!=-1 && s[i]!=s[j]){
            j = kmp[j];
        }
        j++;
        i++;
        kmp[i] = j;
    }
    return kmp;
}

void solve(){
   int n;
   cin>>n;
   string s;
   cin>>s;

   vector<int> kmp = KMP(s,n);
   
   int length = -1;

   for(int i=2;i<n;i++){
    if(kmp[i]==kmp[n]){
        length = kmp[i];
        break;
    }
   }

   if(kmp[n]==0){
        cout<<-1<<endl;
   }else if(length>0){
        cout<<s.substr(0,length)<<endl;
   }else if(length<=0){
    if(kmp[kmp[n]]==0){
        cout<<-1<<endl;
    }else{
        cout<<s.substr(0,kmp[kmp[n]])<<endl;
    }
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