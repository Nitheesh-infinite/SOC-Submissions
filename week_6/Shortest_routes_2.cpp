// url : https://cses.fi/problemset/task/1672

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> distance(n, vector<ll>(n, INF));
    for (int i = 0; i < n; ++i)
        distance[i][i] = 0;
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        a--, b--;
        distance[a][b] = min(distance[a][b], w);
        distance[b][a] = min(distance[b][a], w); 
    }
    // Floyd-Warshall
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (distance[i][k] < INF && distance[k][j] < INF)
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (distance[a][b] == INF) cout << -1 << "\n";
        else cout << distance[a][b] << "\n";
    }
    return 0;
}
