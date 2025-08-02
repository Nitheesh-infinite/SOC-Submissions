// urL : https://cses.fi/problemset/task/1715

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll MOD =1e9+7;
const int MAX = 1e6+1;
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

ll answer(vector<int> v,ll n){
    ll c = 1;
    c = c*fact[n];
    for(int i = 0;i<26;i++){
        if(v[i] != 0) {c *= inv_fact[v[i]]; c=c%MOD;}
    }
    return c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    string s;
    cin >> s;
    int k = s.size();
    vector<int> a(26,0);
    for(int i=0;i<k;i++){
        a[s[i] -'a']++;
    }
    cout << answer(a,k) << "\n";
}