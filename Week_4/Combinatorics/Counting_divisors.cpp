// url : https://cses.fi/problemset/task/1713

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,count =0;
        cin >> n;
        for(int i=1;i<sqrt(n);i++){
            if(n%i == 0){ count++;}
        }
        int k= sqrt(n);
        if(k*k == n) count = count*2 +1;
        else count = count*2;
        cout << count << "\n";
    }
    return 0;
}