// url : https://cses.fi/problemset/task/1666

#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
vector<vector<int>> nodes;
vector<bool> visited;

void check(int i){
    visited[i] = true;
    for(auto x: nodes[i]){
        if(!visited[x]) check(x);
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
    for(int i=0;i<m;i++){
        cin >> f >> s;
        nodes[f-1].push_back(s-1);
        nodes[s-1].push_back(f-1);
    }
    bool all_found = false;
    int components = 0;
    vector<int> roads;
    while(!all_found){
        for(int i=0;i<n;i++){
            if(!visited[i]) {components++;check(i);roads.push_back(i);}
        }
        all_found = true;
        for(int i=0;i<n;i++){
            if(!visited[i]) {all_found = false;break;}
        }
    }
    cout << components-1 <<"\n";
    int k = roads.size();
    for(int i=0;i<k-1;i++){
        cout << roads[i]+1 << " " << roads[i+1]+1 << "\n";
    }
}