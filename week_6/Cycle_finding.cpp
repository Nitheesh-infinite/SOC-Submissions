// url : https://cses.fi/problemset/task/1197

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
vector<ll> distances;
vector<bool> visited;
vector<int> previous;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,ll>>> graph(n);
    distances.assign(n,INF);
    visited.assign(n,false);
    previous.assign(n,1);
    for(int i=0;i<m;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        graph[a-1].push_back({b-1,w});
}