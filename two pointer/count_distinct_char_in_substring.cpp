#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>> indx(26);
    for(int i=0;i<n;i++){
        indx[s[i]-'a'].push_back(i);
    }
    int ans = 26*(((n)*(n+1))/2);
    for(auto v:indx){
        vector<int> temp = v;
        int m = temp.size();
        if(m==0){
            ans -= (n*(n+1))/2;
        }else if(m==1){
            int left = temp[0]-0;
            int right = n-temp[0]-1;
            ans -= (left*(left+1))/2;
            ans -= (right*(right+1))/2;
        }else{
            for(int i=0;i<m;i++){
                int left;
                int right;
                if(i==0){
                    left = temp[i]-0;
                    right = temp[i+1]-temp[i]-1;
                    ans -= (left*(left+1))/2;
                    ans -= (right*(right+1))/2;
                }else if(i==m-1){
                    left = temp[i]-temp[i-1]-1;
                    right = n-temp[i]-1;
                    ans -= (right*(right+1))/2;
                }else{
                    left = temp[i]-temp[i-1]-1;
                    right = temp[i+1]-temp[i]-1;
                    ans -= (right*(right+1))/2;
                }
                
            }
        }

    }

    cout<<ans<<endl;

}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
