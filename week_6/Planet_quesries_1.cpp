// url : https://cses.fi/problemset/task/1750

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int LOG = 30;
int jump[MAXN][LOG];  // jump[i][j] = node you reach from i after 2^j steps
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> jump[i][0]; 
        jump[i][0]--;     
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            jump[i][j] = jump[jump[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        x--; 
        for (int i = 0; i < LOG; i++) {
            if (k & (1 << i)) {
                x = jump[x][i];
            }
        }
        cout << x + 1 << "\n";
    }

    return 0;
}
