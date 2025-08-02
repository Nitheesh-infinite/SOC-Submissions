#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited, in_stack;
vector<int> parent;
int cycle_start = -1, cycle_end = -1;

bool dfs(int u) {
    visited[u] = true;
    in_stack[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            if (dfs(v)) return true;
        } else if (in_stack[v]) {
            cycle_end = u;
            cycle_start = v;
            return true;
        }
    }

    in_stack[u] = false;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    adj.assign(n, {});
    visited.assign(n, false);
    in_stack.assign(n, false);
    parent.assign(n, -1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i] && dfs(i))
            break;
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for (int node : cycle)
            cout << node + 1 << " ";
        cout << "\n";
    }

    return 0;
}
