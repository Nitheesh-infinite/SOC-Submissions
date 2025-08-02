// url : https://cses.fi/problemset/task/1637

#include<bits/stdc++.h>
using namespace std;

vector<int> memo;
int n_digits(int n){
    if( n == 0 ) return 0;
    else if(memo[n] != -1) return memo[n];
    int y = n;
    int max = -1;
    while(y > 0){
        int d = y%10;
        max = d > max?d:max;
        y=y/10;
    }
    int count = 0;
    count = 1 + n_digits(n - max);
    return memo[n] = count;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    memo.assign(n+1,-1);
    cout << n_digits(n) << "\n";

}