// url : https://cses.fi/problemset/task/1745

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e5+5;

vector<vector<bool>> memo;

void solve(int idx, int sum, vector<int>& v, int n) {
    if (memo[idx][sum]) return; 
    memo[idx][sum] = true;

    if (idx == n) return;

    solve(idx + 1, sum, v, n);          
    solve(idx + 1, sum + v[idx], v, n);    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    int s = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        s += v[i];
    }

    memo.assign(n + 1, vector<bool>(s + 1, false));
    solve(0, 0, v, n);

    vector<int> res;
    for(int i = 1; i <= s; i++) {
        if (memo[n][i]) res.push_back(i);
    }

    cout << res.size() << "\n";
    for (int x : res) cout << x << " ";
    cout << "\n";
}
