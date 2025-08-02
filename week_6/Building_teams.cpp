// url : https://cses.fi/problemset/task/1666

#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
vector<vector<int>> nodes;
vector<bool> visited;
vector<int> teams;
void check(int i,bool& found){
    visited[i] = true;
    for(auto x: nodes[i]){
        if(teams[x] != teams[i] && !visited[x] && !found) {teams[x] = teams[i]==1?2:1;check(x,found);}
        else if( teams[x] == teams[i]) found = true;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int f,s;
    nodes.assign(n,vector<int>());
    visited.assign(n,false);
    teams.assign(n,-1);
    for(int i=0;i<m;i++){
        cin >> f >> s;
        nodes[f-1].push_back(s-1);
        nodes[s-1].push_back(f-1);
    }
    bool all_found = false;
    bool found = false;
    while(!all_found){
        for(int i=0;i<n;i++){
            if(!visited[i]) {teams[i] = 1;check(i,found);}
        }
        all_found = true;
        for(int i=0;i<n;i++){
            if(!visited[i]) {all_found = false;break;}
        }
    }
    if(found) {cout << "IMPOSSIBLE" << "\n" ;return 0;}
    else {
        for(int i=0;i<n;i++){
            cout << teams[i]<<" " ;
        }
        cout << "\n";
    }
}