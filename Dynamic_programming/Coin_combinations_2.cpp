// url : https://cses.fi/problemset/task/1636

#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
vector<int> memo;

int cases(vector<int> a,int x,int n){
    if(memo[x] != -1) return memo[x];
    else if(x < 0) return 0;
    else if(x==0) return 1;
    int count = 0;
    for(int i=n;i>0;i--){ count += cases(a,x-a[i-1],n); }
    return memo[x] = (count%MOD + MOD)%MOD ;
}

int main(){
    int n,x;
    cin >>n >>x;
    memo.assign(x+1,-1);
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    cout << cases(a,x,n) << "\n";
}