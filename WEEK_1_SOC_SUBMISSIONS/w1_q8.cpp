// url : https://cses.fi/problemset/task/1754

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
    int a,b;
    cin >> a>>b;
    if( 2*a-b <0 || 2*b - a < 0 ){
        cout << "NO"<<"\n";
    }
    else if( (2*a-b)%3==0 && (2*b-a)%3==0 ){
        cout << "YES"<<"\n";
    }
    else {
        cout << "NO" << "\n";
    }
    }

    return 0;
}