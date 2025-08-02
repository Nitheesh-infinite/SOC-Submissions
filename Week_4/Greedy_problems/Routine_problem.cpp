// url : https://codeforces.com/contest/337/problem/B

#include <bits/stdc++.h>
using namespace std;

void fract(int num, int denom, int& out_num, int& out_denom) {
    int g = __gcd(num, denom);
    out_num = num / g;
    out_denom = denom / g;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int o = a * d - b * c;
    int num, denom;

    if (o < 0) {
        o = -o;
        fract(o, b * c, num, denom);
        cout << num << "/" << denom << "\n";
    } else if (o > 0) {
        fract(o, a * d, num, denom);
        cout << num << "/" << denom << "\n";
    } else {
        cout << 0<<"/"<<1 << "\n";
    }

    return 0;
}
