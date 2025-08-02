// url : https://cses.fi/problemset/task/1681

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e5+1;
vector<vector<int>> graph;
ll from_1[MAX];
ll to_n[MAX];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    graph.assign(n,vector<int>());
    for(int i=0;i<m;i++){
        int x,y;
        graph[x-1].push_back(y-1);
    }
    priority_queue<
}