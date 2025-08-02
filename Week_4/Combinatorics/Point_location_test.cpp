// url : https://cses.fi/problemset/task/2189/

#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        ll cross = 1LL * (x2 - x1) * (y3 - y1) - 1LL * (y2 - y1) * (x3 - x1);
        if (cross == 0)
            cout << "TOUCH\n";
        else if (cross > 0)
            cout << "LEFT\n";
        else
            cout << "RIGHT\n";
    }

    return 0;
}
