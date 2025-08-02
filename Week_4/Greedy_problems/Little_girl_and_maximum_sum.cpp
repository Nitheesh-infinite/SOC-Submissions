// url : https://codeforces.com/contest/276/problem/C

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n, q;
//     cin >> n >> q;

//     vector<ll> v(n);
//     for (int i = 0; i < n; i++) {
//         cin >> v[i];
//     }

//     vector<ll> freq(n, 0); 

//     for (int i = 0; i < q; i++) {
//         int l, r;
//         cin >> l >> r;
//         for (int j = l - 1; j < r; j++) {
//             freq[j]++;
//         }
//     }

//     sort(v.begin(), v.end());
//     sort(freq.begin(), freq.end());

//     ll sum = 0;
//     for (int i = 0; i < n; i++) {
//         sum += v[i] * freq[i]; 
//     }

//     cout << sum << "\n";
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<ll> freq(n + 1, 0);

    while (q--) {
        int l, r;
        cin >> l >> r;
        freq[l - 1] += 1;
        freq[r] -= 1;
    }

    for (int i = 1; i < n; i++) {
        freq[i] += freq[i - 1];
    }
    freq.pop_back();

    sort(v.begin(), v.end());
    sort(freq.begin(), freq.end());

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i] * freq[i];
    }

    cout << sum << "\n";
}
