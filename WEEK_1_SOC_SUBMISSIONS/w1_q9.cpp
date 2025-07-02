// url : https://codeforces.com/problemset/problem/1806/A

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >>t;
    for(int i=0;i<t;i++){
        int a,b,c,d;
        cin >>a>>b>>c>>d;
        if(d-b>=0){
            if (a-b+d >= c){
                cout << 2*(d-b)+a-c<<"\n";
            } 
            else cout << -1<<"\n";
        }
        else cout << -1<<"\n";
    }
    return 0;
}