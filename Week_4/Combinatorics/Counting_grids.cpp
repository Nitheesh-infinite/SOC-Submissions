// url : https://cses.fi/problemset/task/2210

#include<bits/stdc++.h>
using namespace std;

#define ll long long 

const ll MOD = 1e9+7;

ll mod_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

ll divide_by_4_mod(ll x) {
    ll inv4 = mod_pow(4, MOD - 2, MOD);
    return (x * inv4) % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n ;
    ll n2 = n * n;
    ll term1 = mod_pow(2, n2, MOD);
    ll term2,term3;
    if(n%2 == 0){
        term2 = mod_pow(2, n2 / 4 + 1, MOD);
        term3 = mod_pow(2, n2 / 2, MOD);
    }
    else {
        term2 = mod_pow(2,(n2+7)/4,MOD);
        term3 = mod_pow(2,(n2+1)/2,MOD);
    }
    ll result = (term1 + term2 + term3) % MOD;
    cout << divide_by_4_mod(result);
    return 0;
}