// url : https://cses.fi/problemset/task/2064

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;
const int MAX = 1e6+1;

vector<ll> fact(MAX), inv_fact(MAX);

ll mod_pow(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while(b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for(int i = 1; i < MAX; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    inv_fact[MAX - 1] = mod_pow(fact[MAX - 1], MOD - 2, MOD);
    for(int i = MAX - 2; i >= 0; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n]*inv_fact[r]%MOD*inv_fact[n - r]%MOD;
}

ll catalan(int n) {
    if (n == 0) return 1;
    return nCr(2*n,n)*mod_pow(n + 1, MOD-2, MOD)%MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    precompute();
    int n;
    cin >> n;
    if (n % 2 != 0) cout << 0 << "\n";
    string s;
    cin >>s;
    
    return 0;
}
