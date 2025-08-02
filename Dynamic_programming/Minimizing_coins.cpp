// url : https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
vector<int> memo;

int min_coins(int n, int k, int v[]) {
    if (k < 0) return INF;
    if (k == 0) return 0;
    if (memo[k] != -1) return memo[k];
    int res = INF;
    for (int i = 0; i < n; i++) {
        res = min(res, 1 + min_coins(n, k - v[i], v));
    }
    return memo[k] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memo.assign(k + 1, -1);
    int ans = min_coins(n, k, a);
    cout << ((ans == INF)?-1:ans) << "\n";
}
