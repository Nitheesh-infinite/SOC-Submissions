// url : https://cses.fi/problemset/task/1669

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
vector<vector<int>> nodes;
vector<bool> visited;
vector<int> previous;

int cycle_start = -1, cycle_end = -1;

void search(int i, bool& found) {
    visited[i] = true;
    for (int x : nodes[i]) {
        if (x == previous[i]) continue; 
        if (!visited[x]) {
            previous[x] = i;
            search(x, found);
            if (found) return;
        } else {
            cycle_start = x;
            cycle_end = i;
            found = true;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    nodes.assign(n, vector<int>());
    previous.assign(n, -1);
    visited.assign(n, false);
    int f, s;
    for (int i = 0; i < m; i++) {
        cin >> f >> s;
        nodes[f - 1].push_back(s - 1);
        nodes[s - 1].push_back(f - 1);
    }
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            search(i, found);
            if (found) break;
        }
    }
    if (!found) {cout << "IMPOSSIBLE\n";return 0;}
    vector<int> cycle;
    cycle.push_back(cycle_start + 1);
    int cur = cycle_end;
    while (cur != cycle_start) {
        cycle.push_back(cur + 1);
        cur = previous[cur];
    }
    cycle.push_back(cycle_start + 1);
    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << "\n";
    for (int x : cycle) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
