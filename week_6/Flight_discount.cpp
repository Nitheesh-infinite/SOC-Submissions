#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        graph[u - 1].emplace_back(v - 1, w);
    }
    // dist[node][0] = min distance to node without discount used
    // dist[node][1] = min distance to node with discount used
    vector<vector<ll>> dist(n, vector<ll>(2, INF));
    dist[0][0] = 0;
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;
    pq.emplace(0, 0, 0);  // {distance, node, discountUsed}
    while (!pq.empty()) {
        auto [d, u, used] = pq.top();
        pq.pop();
        if (d > dist[u][used]) continue;
        for (auto [v, w] : graph[u]) {
            // Case 1: Don't use discount
            if (dist[v][used] > dist[u][used] + w) {
                dist[v][used] = dist[u][used] + w;
                pq.emplace(dist[v][used], v, used);
            }
            // Case 2: Use discount (if not already used)
            if (used == 0 && dist[v][1] > dist[u][0] + w / 2) {
                dist[v][1] = dist[u][0] + w / 2;
                pq.emplace(dist[v][1], v, 1);
            }
        }
    }
    cout << dist[n - 1][1] << '\n';
}
