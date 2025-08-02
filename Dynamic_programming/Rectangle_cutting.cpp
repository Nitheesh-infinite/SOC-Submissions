// url : https://cses.fi/problemset/task/1744

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin >> a>> b;
    vector<vector<int>> moves(a+1,vector<int>(b+1));
    for(int i = 0;i<=a;i++){
        for(int j =0;j<=b;j++){
            if( i == j ) moves[i][j] = 0;
            else if( i == 0) moves[i][j] = j ;
            else if( j == 0) moves[i][j] = i ;
        }
    }
    for(int i = 1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if (i == j) moves[i][j] = 0;
            else {
                moves[i][j] = INF;
                for (int x = 1; x < i; ++x) moves[i][j] = min(moves[i][j], moves[x][j] + moves[i - x][j] + 1);
                for (int y = 1; y < j; ++y) moves[i][j] = min(moves[i][j], moves[i][y] + moves[i][j - y] + 1);
            }
        }
    }
    cout << moves[a][b] << "\n";
}