// url : https://cses.fi/problemset/task/1716

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll MAX = 2e6 + 5; 
const ll MOD = 1e9 + 7;

vector<ll> fact(MAX), inv_fact(MAX);

ll mod_pow(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (ll i = 1; i < MAX; ++i)
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[MAX - 1] = mod_pow(fact[MAX - 1], MOD - 2, MOD);
    for (ll i = MAX - 2; i >= 0; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    precompute();
    ll n,m; 
    cin >> n>> m;
    cout << nCr(n+m-1,m)<< "\n";

    return 0;
}