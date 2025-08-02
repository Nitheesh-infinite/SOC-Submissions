// url : https://cses.fi/problemset/task/2168

#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int in(ll a,ll b,ll c,ll d){
    if( a==c && b==d ) return 0;
    if(a <= c && b >= d) return 1;
    else return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<pair<ll,ll>> m;
    for(int i=0;i<n;i++){
        ll a,b;
        cin >> a>>b;
        m.push_back(make_pair(a,b));
    }
    vector<int> a1(n,0);
    vector<int> a2(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(in(m[i].first,m[i].second,m[j].first,m[j].second) == 1) {a1[i]++;}
            if(in(m[j].first,m[j].second,m[i].first,m[i].second) == 1) {a2[i]++;}
        }
    }
    for(int i=0;i<n;i++){
        cout << a1[i] << " ";
    }
    cout << "\n";
    for(int i=0;i<n;i++){
        cout << a2[i] << " ";
    }
    cout << "\n";
    return 0;
}