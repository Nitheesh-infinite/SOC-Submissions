// url : https://cses.fi/problemset/task/1638

#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
vector<vector<int>> memo;

int grid_paths(const vector<vector<char>>& b,int x,int y){
    if(x < 1 || y < 1) return 0;
    else if(b[x-1][y-1] == '*') return 0;
    else if( x == 1 && y == 1) return 1;
    else if(memo[x-1][y-1] != -1) return memo[x-1][y-1];

    memo[x-1][y-1] = (grid_paths(b,x-1,y) + grid_paths(b,x,y-1))%MOD;
    return memo[x-1][y-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    memo.assign(n,vector<int>(n,-1));
    vector<vector<char>> b(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char s;
            cin >> s;
            b[i].push_back(s);
        }
    }
    cout << grid_paths(b,n,n) << "\n";
    
}