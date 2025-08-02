// url : https://cses.fi/problemset/task/1145

#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int> memo(n,-1);
    memo[0] = 1;
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if( a[i] > a[j]) {memo[i] = max(memo[i],memo[j] +1);}
        }
        if(memo[i] == -1) memo[i] = memo[i-1];
    }
    int max = -1;
    for(int i=0;i<n;i++){
        if( max < memo[i] ) max = memo[i];
    }
    cout << max << "\n";
}