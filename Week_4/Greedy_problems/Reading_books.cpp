// url : https://cses.fi/problemset/task/1631

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n;
    cin >> n;
    vector<ll> v;
    ll k = 0;
    for(int i=0;i<n;i++){
        ll a;
        cin >> a;
        v.push_back(a);
        k+=a;
    }
    sort(v.begin(),v.end());
    ll count = 0;
    for(int i=0;i<n;i++){
        count += v[i]; 
        if( count > k/2){
            count -= v[i];
            break;
        }
    }
    cout << 2*k - 2*count << "\n";
}