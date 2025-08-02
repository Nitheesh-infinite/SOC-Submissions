// url : https://cses.fi/problemset/task/1160

#include<bits/stdc++.h>
using namespace std;
const int INF = 2e5+1;
vector<vector<int>> p;
vector<vector<int>> distances;
int n,q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>> n >> q;
    p.assign(n,vector<int>());
    distances.assign(n,vector<int>(n,INF));
    vector<int> o(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        o[i] = a-1;
        p[a-1].push_back(i);
        if(i != a-1) distances[i][a-1] = 1;
        else distances[i][a-1] = 0;
    }
    for(int i=0;i<n;i++){
        for(auto x : p[i]){
            distances[x][o[i]] = min(distances[x][o[i]],distances[i][o[i]] + 1);
        }
    }
    for(int i=0;i<q;i++){
        int y,z;
        cin>> y >> z;
        if( distances[y-1][z-1] != INF ) cout << distances[y-1][z-1] << "\n";
        else cout << -1 << "\n";
    }
}