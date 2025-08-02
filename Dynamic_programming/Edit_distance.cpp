// url : https://cses.fi/problemset/task/1639

#include<bits/stdc++.h>
#include <algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1,s2;
    cin >> s1>>s2;

    int N = s1.length(),M = s2.length();
    int dp[N+1][M+1];
    for(int i = 0; i < N+1; i++) dp[i][0] = i;
    for(int i = 0; i < M+1; i++) dp[0][i] = i;
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++){
            if( s1[i -1] == s2[j - 1] ) dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])); // delete,replace,insert
            } 
        }
    }
    cout << dp[N][M] << "\n";

}