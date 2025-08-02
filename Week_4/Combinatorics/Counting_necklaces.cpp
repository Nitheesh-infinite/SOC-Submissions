// url : https://cses.fi/problemset/task/2209

#include<bits/stdc++.h>
using namespace std;

#define ll long long 

const ll MOD = 1e9+7;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}


ll mod_pow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll necklaces(ll n, ll m) {
    ll s = 0;
    for (ll i = 0; i < n; ++i) {
        s = (s + mod_pow(m, gcd(i, n), MOD)) % MOD;
    }
    s = s * mod_pow(n, MOD - 2, MOD) % MOD;
    return s;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    
    cout << necklaces(n,m)<< "\n";
    return 0;
}