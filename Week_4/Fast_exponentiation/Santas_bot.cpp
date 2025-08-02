// url : https://codeforces.com/contest/1279/problem/D

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define ll long long
#define vi vector<ll>

bool existsInVector(const vector<ll>& v, ll x) {
    return find(v.begin(), v.end(), x) != v.end();
}

ll mod_pow(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll mod_inverse(ll a, ll m) {
    return mod_pow(a, m - 2, m); 
}

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    vector<vector<ll>> a;
    vector<pair<ll,ll>> p;
    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> k;
        p.push_back(make_pair(1,k));
        vi b;
        ll l;
        for(int j=0;j<k;j++){cin >> l; b.push_back(l);}
        a.push_back(b);
    }
    ll numer=1,denom=1;
    for(ll t=0;t<n;t++){
        for(ll y=0;y<p[t].second;y++){
            ll no_of_contains =1;
            for(ll o =0;o<n;o++){
                if(existsInVector(a[o],a[t][y])){
                    no_of_contains++;
                    if(numer==1 && denom==1){numer = 1;denom = n*p[o].second;}
                    else {numer = numer*n*p[o].second + denom*1;
                    denom = denom*n*p[o].second;}
                }
            }
            numer *= no_of_contains;
            denom *= n;
        }
    }
    ll f = gcd(numer,denom);
    numer /= f;
    denom /= f;
    cout << (numer*mod_inverse(denom,998244353))%998244353;
    return 0;
}