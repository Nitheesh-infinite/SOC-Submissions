// url : https://cses.fi/problemset/task/1712/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll exponentiation(ll a, ll b, ll m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll exponent_exponent(ll a,ll b,ll c,ll m){ // Eulers theorem
    ll k = exponentiation(b,c,1e9+6);
    return exponentiation(a,k,1e9+7);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a>>b>>c;
        cout << exponent_exponent(a,b,c,1e9+7)<< "\n";
    }
    return 0;
}