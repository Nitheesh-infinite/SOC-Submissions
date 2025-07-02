#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;

    for(ll k = 1; k <= n; ++k){
        ll total_positions = (k * k) * (k * k - 1) / 2;
        ll attacking_positions = 4 * (k - 1) * (k - 2);
        cout << total_positions - attacking_positions << "\n";
    }

    return 0;
}
