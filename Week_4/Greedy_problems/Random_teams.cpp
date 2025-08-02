// url : https://codeforces.com/contest/478/problem/B

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a,b;
    cin >> a>> b;
    ll k_max = (a-b)*(a-b+1)/2;
    ll r = a/b;
    ll p = a - b*r;
    ll k_min = p*(r)*(r+1)/2+(b-p)*r*(r-1)/2;
    cout << k_min << " "<< k_max<<"\n" ;

    return 0;
}