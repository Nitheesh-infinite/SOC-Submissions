// url : https://cses.fi/problemset/task/1667

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e5;
vector<int> distances;
vector<vector<int>> nodes;
bool visited[INF];
vector<int> previous;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n>> m;
    distances.assign(n,INF);
    nodes.assign(n,vector<int>());
    previous.assign(n,-1);
    int f,s;
    for(int i=0;i<m;i++){
        cin >> f >> s;
        nodes[f-1].push_back(s-1);
        nodes[s-1].push_back(f-1);
    }
    queue<int> q;
    visited[0] = true;
    distances[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto u : nodes[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            previous[u] = s;
            distances[u] = distances[s]+1;
            q.push(u);
        }
    }
    if(distances[n-1] == INF) {cout << "IMPOSSIBLE" << "\n";return 0;}
    else {
        cout << distances[n-1] +1 << "\n";
        int current = n-1;
        vector<int> k;
        k.push_back(n);
        while(current){
            k.push_back(previous[current] +1);
            current = previous[current]; 
        }
        reverse(k.begin(),k.end());
        for(int x: k){
            cout << x <<" ";
        }
    }
}