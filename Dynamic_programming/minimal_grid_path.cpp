// url : https://cses.fi/problemset/task/3359

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    // DP table: dp[i][j] is the minimal string to reach (i, j)
    vector<vector<string>> dp(n, vector<string>(n));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
    for (int j = 1; j < n; j++) dp[0][j] = dp[0][j-1] + grid[0][j];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (dp[i-1][j] < dp[i][j-1])
                dp[i][j] = dp[i-1][j] + grid[i][j];
            else
                dp[i][j] = dp[i][j-1] + grid[i][j];
        }
    }
    cout << dp[n-1][n-1] << '\n';
}



// some where is the problem

// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<string>> memo;

// string solve(vector<string>& v,int i,int j,int& n){
//     if( memo[i][j] != "a") return memo[i][j];
//     else if( i == n-1 && j == n-1) return memo[i][j] = v[i][j];
//     else if( j == n-1 ) return memo[i][j] = v[i][j] + solve(v,i+1,j,n);
//     else if( i == n-1 ) return memo[i][j] = v[i][j] + solve(v,i,j+1,n);
//     string s = "";
//     s += v[i][j];
//     string down = solve(v, i+1, j, n);
//     string right = solve(v, i, j+1, n);
//     if (down > right) s += right;
//     else s += down;
//     return memo[i][j] = s;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n;
//     cin >> n;
//     vector<string> v(n);
//     for( int i = 0;i<n;i++ ) cin >> v[i];
//     memo.assign(n,vector<string>(n,"a"));
//     cout << solve(v,0,0,n) << "\n";
// }
