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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        ll a,b;
        cin >> a>>b;
        cout << exponentiation(a,b,1e9+7)<< "\n";
    }
}