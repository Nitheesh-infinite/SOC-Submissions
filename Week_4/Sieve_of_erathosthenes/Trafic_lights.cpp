// url : https://cses.fi/problemset/task/1163/

#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x,n;
    cin >>x >>n;
    vector<ll> v;
    for(int i=0;i<n;i++){
        ll c;
        cin>> c;
        v.push_back(c);
        sort(v.begin(),v.end());
        ll max = v[0];
        for(ll i =1 ;i<=v.size()-1;i++){
            if(max < (v[i] - v[i-1] -1)) max = (v[i] - v[i-1] - 1) ;
        } 
        if( max < (x - v[v.size()-1])) max = (x-v[v.size()-1]);
        cout << max << " ";  
    }
    cout << "\n";
    return 0;
}