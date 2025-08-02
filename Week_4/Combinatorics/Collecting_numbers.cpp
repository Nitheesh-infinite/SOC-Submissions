// url : https://cses.fi/problemset/task/2216

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> v;
    for(ll i=0;i<n;i++){
        ll k;
        cin >> k;
        v.push_back(k);
    }
    ll current=1;
    ll k=0;
    while(current <= n){
        k++;
        for(int i=0;i<n;i++){
           if( v[i] == current ){
                current++;
           }
        }
    }
    cout << k << "\n";
    return 0;
}