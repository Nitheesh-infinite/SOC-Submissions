// url : https://cses.fi/problemset/task/1635

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
vector<int> memo;

int answer(int x,int n,int a[]){
    if(memo[x] != -1){ return memo[x];}
    else if( x < 0 ) return 0;
    else if(x == 0) return 1;
    int c = 0;
    for(int i=0;i<n;i++){
        if(x - a[i] >= 0) c = (c + answer(x-a[i],n,a))%INF;
    }
    return memo[x] = c ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,x;
    cin>> n >> x;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    memo.assign(x+1,-1);
    cout << answer(x,n,a) << "\n";
}