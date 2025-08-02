// url : https://cses.fi/problemset/task/3403

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<ll> a(n),b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i]; 
    ll k[n+1][m+1];
    for(int i=0;i<=n;i++) k[i][0] = 0;
    for(int j=0;j<=m;j++) k[0][j] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(a[i] != b[j]) k[i][j] = max({k[i-1][j], k[i][j-1]});
            else k[i][j] = 1 + max({k[i-1][j], k[i][j-1]});
        }
    }
    cout << k[n][m] << "\n";
}