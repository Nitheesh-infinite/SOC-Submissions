// url : https://www.spoj.com/problems/SQFREE/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX = 1e7 + 5; 

int mobius[MAX];

void compute_mobius() {
    for (int i = 0; i < MAX; ++i) mobius[i] = 1;
    vector<bool> is_prime(MAX, true);

    for (int i = 2; i < MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i; j < MAX; j += i) {
                mobius[j] *= -1;
                is_prime[j] = false;
            }
            for (ll j = 1LL * i * i; j < MAX; j += 1LL * i * i) {
                mobius[j] = 0;
            }
        }
    }
}

ll count_square_free(ll n) {
    ll res = 0;
    for (ll i = 1; i * i <= n; ++i) {
        res += mobius[i] * (n / (i * i));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    compute_mobius();
    
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << count_square_free(n) << "\n";
    }

    return 0;
}
