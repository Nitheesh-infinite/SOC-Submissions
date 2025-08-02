// url : https://cses.fi/problemset/task/1746

#include<bits/stdc++.h>
using namespace std;

int cases(pair<int,int> p,vector<int>& v,int i,int m){
    if( i == 0 ) return 1;
    int y = 3;
    int count = 0;
    while(y --){
        if(abs(v[p.second] - v[p.first] - y + 2) <= i - 1 && v[p.first] - y + 2 <= m && v[p.first] - y + 2 >= 1 ){
            v[p.first+1] = v[p.first] - y + 2;
            count += cases(make_pair(p.first+1,p.second),v,i-1,m);
        }
    }
    return count;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    int prev = 0,now = 0;
    vector<pair<int,int>> pairs;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i] != 0 && a[i] - a[now] > i - now) {cout << 0 << "\n"; return 0;}
        if(a[i] != 0) { prev = now;now = i;pairs.push_back(make_pair(prev,now));}
    }
    if(prev = now = 0){ }
    int k = 0;
    for(auto x : pairs){
        k += cases(x,a,x.second-x.first,m);
    }
    cout << k << "\n"; 
}