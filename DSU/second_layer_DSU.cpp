#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


struct second_DSU{
    vector<int> player_team;
    vector<int> team_parent;
    vector<int> team_size;
    vector<int> team_rank;//number of teams
    vector<map<int,int>> num_freq; // jersy number 
    void init(int n, int m){
        //n -> number of players
        //m-> number of team
        player_team.assign(n+1,-1); //this one maintain player assign to which team, in starting no player assign to any team so -1
        team_parent.resize(m+1); //parent of every team or team may be merge so maintain the root of teams , initially every team are individual so they are there own parents
        team_size.assign(m+1,0); //no. of player in any team at starting
        team_rank.resize(m+1);//no.of team after merging some team, initial every team is single
        num_freq.resize(m+1); 
        for(int i=1;i<=m;i++){
            team_parent[i] = i;
        }
    }

    int find(int a){
        if(team_parent[a]==a){
            return a;
        }
        return team_parent[a] =  find(team_parent[a]);
    }

    void merge(int a, int b){
        int aroot = find(a);
        int broot = find(b);
        if(aroot != broot){
            if(team_rank[aroot]<team_rank[broot]){
                swap(aroot,broot);
            }
            team_rank[aroot]+=team_rank[broot];
            team_size[aroot]+=team_size[broot];
            team_parent[broot]=aroot; 

            for(auto v:num_freq[broot]){
                num_freq[aroot][v.first]+=v.second;
            }
            num_freq[broot].clear();
        }
    }
};

int n,m;
int q;
void solve(){
   cin>>n>>m;

   second_DSU dsu;
   dsu.init(n,m);
   vector<int> num(n+1);
   for(int i=1;i<=n;i++){
    //every player have given number on there jersy
    cin>>num[i];
   }
   cin>>q;
   while(q--){
    int ch;
    cin>>ch;
    if(ch==1){
        //put player x to team a;
        int x,a;
        cin>>x>>a;
        if(dsu.player_team[x]!=-1){
            //if player already assign to any team
            int xTeam = dsu.find(dsu.player_team[x]); // find which team it belong to
            dsu.team_size[xTeam]--; //decrease it size of team by one because x going to assgin to another team
            dsu.num_freq[xTeam][num[x]]--; //decrease frequency of jersey
            if(dsu.num_freq[xTeam][num[x]]==0){ //if it became zero delete it 
                dsu.num_freq[xTeam].erase(num[x]);
            }
        }
        dsu.player_team[x]=a; // assign new team to player x
        int xTeam = dsu.find(dsu.player_team[x]); //find parent of team a
        dsu.team_size[xTeam]++; // increase the team size of that parent team to which team a belong
        dsu.num_freq[xTeam][num[x]]++; // incream the frequency of jersy
    }else if(ch==2){
        //meege team a and b
        int a,b;
        cin>>a>>b;
        dsu.merge(a,b);
    }else if(ch==3){
        // check player x and y belong to same team or not
        int x,y;
        cin>>x>>y;
        int xTeam = dsu.player_team[x];
        int yTeam = dsu.player_team[y];
        if(xTeam!=-1 && yTeam!=-1){
            if(dsu.find(xTeam)==dsu.find(yTeam)){
                cout<<"Yes"<<endl;
            }else{
                cout<<"Not belong to same team"<<endl;
            }
        }else{
            cout<<"both of them or one of them not assign to team"<<endl;
        }
    }else if(ch==4){
        //return the size of team from which player x belongs
        int x;
        cin>>x;
        int xTeam = dsu.player_team[x];
        if(xTeam==-1){
            cout<<"Not part of any team"<<endl;
        }else{
            int par = dsu.find(xTeam);
            cout<<dsu.team_size[par]<<endl;
        }
    }else if(ch==5){
        // find number of the distinct number of jersey in the team of player x
        int x;
        cin>>x;
        int xTeam = dsu.player_team[x];
        if(xTeam==-1){
            cout<<"Not part of any team"<<endl;
        }else{
            int par = dsu.find(xTeam);
            cout<<dsu.num_freq[par].size()<<endl;
        }
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