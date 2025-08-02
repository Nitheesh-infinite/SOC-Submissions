// url : https://codeforces.com/contest/1425/problem/A

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long

// map<pair<ll,bool>,ll> memo;

// ll greedy(ll n,bool turn){
//     if (n == 1) return turn ? 1 : 0;
//     if( memo.find({n,turn}) != memo.end()){
//         return memo[{n,turn}];
//     }
//     if(turn){
//         if( n%2 == 1 ) return 1 + greedy(n-1,false);
//         else {
//             ll halfed = n/2 + greedy(n/2,false);
//             ll k = 1 + greedy(n-1,false);
//             if (halfed > k){
//                 memo[{n,true}] = halfed;
//                 return memo[{n,true}];
//             }
//             else {
//                 memo[{n,true}] = k;
//                 return k;
//             }
//         }
//     }
//     else {
//         if( n%2 == 1 ) return greedy(n-1,true);
//         else{
//             ll halfed = greedy(n/2,true);
//             ll k = greedy(n-1,true);
//             if(halfed > k){
//                 memo[{n,turn}] = k;
//                 return k;
//             }
//             else {
//                 memo[{n,turn}] = halfed;
//                 return halfed;
//             }
//         }

//     }
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int t;
//     cin >> t;
//     while (t--){
//         ll n;
//         cin >> n;
//         cout << greedy(n,true) <<"\n";
//     }
    
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<ll, ll> dp1; // turn == true
unordered_map<ll, ll> dp0; // turn == false

ll greedy(ll n, bool turn) {
    if (n == 1) return turn ? 1 : 0;

    if (turn && dp1.count(n)) return dp1[n];
    if (!turn && dp0.count(n)) return dp0[n];

    ll res;
    if (turn) {
        if (n % 2 == 1) {
            res = 1 + greedy(n - 1, false);
        } else {
            res = max(1 + greedy(n - 1, false), n / 2 + greedy(n / 2, false));
        }
        dp1[n] = res;
    } else {
        if (n % 2 == 1) {
            res = greedy(n - 1, true);
        } else {
            res = min(greedy(n - 1, true), greedy(n / 2, true));
        }
        dp0[n] = res;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << greedy(n, true) << "\n";
    }
}
