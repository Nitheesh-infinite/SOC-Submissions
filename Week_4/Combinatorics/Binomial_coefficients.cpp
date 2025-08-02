// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// const ll MOD = 1e9 + 7;

// ll mod_pow(ll a, ll b, ll m) {
//     ll res = 1;
//     a %= m;
//     while (b) {
//         if (b & 1) res = res * a % m;
//         a = a * a % m;
//         b >>= 1;
//     }
//     return res;
// }

// ll B_C(ll a, ll b, ll o) {
//     if (b < 0 || b > a) return 0;
//     ll num = 1, den1 = 1, den2 = 1;
//     for (ll i = 1; i <= a; ++i) {
//         num = (num * i) % o;
//         if (i == b) den1 = num;       
//         if (i == a - b) den2 = num;   
//     }
//     ll inv_den = mod_pow((den1 * den2) % o, o - 2, o); 
//     return (num * inv_den) % o;
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; ++i) {
//         ll a, b;
//         cin >> a >> b;
//         cout << B_C(a, b, MOD) << "\n";
//     }
// }

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX = 1e6 + 5; 
const int MOD = 1e9 + 7;

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
    for (int i = 1; i < MAX; ++i)
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[MAX - 1] = mod_pow(fact[MAX - 1], MOD - 2, MOD);
    for (int i = MAX - 2; i >= 0; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precompute(); 

    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;
        cout << nCr(n, r) << "\n";
    }

    return 0;
}

