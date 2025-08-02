// url : https://cses.fi/problemset/task/1630

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    ll d = 0;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a>>b;
        v.push_back(a);
        d += b;
    }
    sort(v.begin(),v.end());
    ll f = 0;
    for(int i=0;i<n;i++){
        f = f + v[i];
        d = d - f ;
    }
    cout << d << "\n";
    return 0;
}