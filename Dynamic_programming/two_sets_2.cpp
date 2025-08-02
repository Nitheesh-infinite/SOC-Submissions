// url : https://cses.fi/problemset/task/1093

// dp[i][x] = number of ways to make sum x using subsets of the numbers 1..i .


#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int target = n*(n+1)/2;
    if (target%2) {
        cout << 0 << "\n";
        return 0;
    }
    target /= 2;

    vector<vector<int>> dp(n,vector<int>(target+1,0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= target; j++) {
        dp[i][j] = dp[i-1][j];
        int left = j-i;
        if (left >= 0) {
        (dp[i][j] += dp[i-1][left]) %= mod;
        }
        }
    }
    cout << dp[n-1][target] << "\n";
}