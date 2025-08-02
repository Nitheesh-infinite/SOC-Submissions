#include <bits/stdc++.h>
using namespace std;

// memo[n] = numver of ways for number n
#define MOD 1000000007

vector<int> memo(1e6 + 5, -1);

int ways(int n) {
    if (n == 0) return 1;
    if (memo[n] != -1) return memo[n];
    int res = 0;
    for (int i = 1; i <= 6; i++) {
        if (n - i >= 0) {
            res = (res + ways(n - i)) % MOD;
        }
    }
    return memo[n] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cout << ways(n) << "\n";
}
