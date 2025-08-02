// url : https://cses.fi/problemset/task/1158

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    vector<int> prices(n);
    for(int i=0;i<n;i++) cin >> prices[i];
    vector<int> pages(n);
    for(int i=0;i<n;i++) cin >> pages[i];
    vector<vector<int>> dp(n+1,vector<int>(x+1));
    for(int i = 0;i < n+1; i++) dp[i][0] = 0;
    for(int i = 0;i < x+1; i++) dp[0][i] = 0;
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= x ; j++){
            if(prices[i-1] <= j)
                dp[i][j] = max(dp[i-1][j], pages[i-1] + dp[i-1][j - prices[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][x] << "\n";
    return 0;
}