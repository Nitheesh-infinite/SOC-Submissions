// url : https://cses.fi/problemset/task/1070

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if( n == 2 || n == 3){cout << "NO SOLUTION" ; return 0;}
    for(int i=2;i<=n;i++){
        if(i%2==0){cout << i << " ";}
    }
    for(int i=1;i<=n;i++){
        if(i%2 == 1){cout << i<<" ";}
    }
    return 0;
}