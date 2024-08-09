#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define int long long
signed main(){
    int n,L;
    cin>>n>>L;
    vector<pair<int,int>> events;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        events.push_back({l,+1});
        events.push_back({r,-1});
    }

    sort(events.begin(),events.end());

    int ans = n; //storing minimum number events present at any point
    int cnt = 0;
    for(int i=0;i<events.size()-1;i++){
        cnt+=events[i].S;
        if(events[i].F!=events[i+1].F){
            ans = min(ans,cnt);
        }
    } 

    int final_ans = n-ans+1;
    //final_ans = (total number of segment) - (minimum number of segment present at any point)+1;
    //plus one because if i remove "ans" from total segment then at some point where total number of segment are equal to "ans" so we have to take one more segment.
    cout<<final_ans<<endl;
}