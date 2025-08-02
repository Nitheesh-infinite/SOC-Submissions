// url : https://cses.fi/problemset/task/1717

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

vector<ll> v(1e6 + 5, -1); 

ll dearrangements(ll n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (v[n] != -1) return v[n];

    return v[n] = ((n - 1) * (dearrangements(n - 1) + dearrangements(n - 2)) % MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    cout << dearrangements(n) << "\n";
    return 0;
}
