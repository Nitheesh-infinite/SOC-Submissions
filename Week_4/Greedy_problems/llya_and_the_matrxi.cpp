#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll layeredPowerSum(vector<ll>& a, int n) {
    sort(a.rbegin(), a.rend()); 
    ll sum = 0;

    for (int k = n; k >= 1; k = k/4) {
        for (int i = 0; i < k; i++) {
            sum += a[i];
        }
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << layeredPowerSum(a, n) << "\n";
}