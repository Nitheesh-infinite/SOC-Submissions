// url : https://cses.fi/problemset/task/1671

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<ll,ll>
const int INF = 1e18;
vector<vector<pii>> adj;
vector<bool> processed;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >>m;
    adj.assign(n+1,vector<pii>());
    processed.assign(n+1,false);
    vector<ll> distance(n + 1, INF);
    ll f,s,t;
    for(int i=0;i<m;i++){
        cin >> f >> s >> t;
        adj[f].push_back({s,t});
    }
    priority_queue<pii,vector<pii>,greater<pii>> q;
    distance[1] = 0;
    q.push({0,1});
    while (!q.empty()) {
        ll a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            ll b = u.first, w = u.second;
            if (distance[a]+w < distance[b]) {
                distance[b] = distance[a]+w;
                q.push({distance[b],b});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << distance[i] <<" ";
    }
    cout << "\n";
}








// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const ll INF = 1e9+1;
// vector<ll> dist;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n,m;
//     cin >> n >>m;
//     dist.assign(n,INF);
//     int f,s,t;
//     vector<tuple<int,int,int>> edges;
//     for(int i=0;i<m;i++){
//         cin >> f >> s >> t;
//         edges.push_back({f,s,t});
//     }
//     dist[0] = 0;
//     for (int i = 1; i <= n-1; i++) {
//         for (auto [a,b,w] : edges) {
//         dist[b-1] = min(dist[b-1], dist[a-1]+w);
//         }
//     }
//     for(int i=0;i<n;i++){
//         cout << dist[i] << " ";
//     }
//     cout << "\n";
// }