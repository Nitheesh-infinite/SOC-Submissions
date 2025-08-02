// url : https://codeforces.com/contest/1130/problem/B

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(2*n);
    map<int,vector<int>> m;

    for(int i = 0; i < 2*n; i++){
        cin >> v[i];
        m[v[i]].push_back(i);
    }

    int sasha = 0, dima = 0;
    long long total_steps = 0;

    for(int i = 1; i <= n; i++){
        int p1 = m[i][0];
        int p2 = m[i][1];

        int option1 = abs(sasha - p1) + abs(dima - p2);
        int option2 = abs(sasha - p2) + abs(dima - p1);

        if(option1 <= option2){
            total_steps += option1;
            sasha = p1;
            dima = p2;
        } else {
            total_steps += option2;
            sasha = p2;
            dima = p1;
        }
    }

    cout << total_steps << "\n";
}
