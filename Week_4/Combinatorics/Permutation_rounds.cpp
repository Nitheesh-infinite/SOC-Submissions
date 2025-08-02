// url : https://cses.fi/problemset/task/3398

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 2e5+1;
const ll MOD = 1e9+7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> k(n);
    for(int i=0;i<n;i++){
        cin >> p[i];
        k[i] = i+1;
    }
    bool sorted = false;
    int count = 0;
    while(!sorted){
        vector<int> o(n);
        for(int i=0;i<n;i++){
            o[p[i]-1] = k[i];
        }
        count = (1+count)%MOD;
        sorted = true;
        for(int i=0;i<n;i++){
            k[i] = o[i]; 
            if( i>0) {
                if(o[i] < o[i-1]) sorted = false;
            }
        }       
    }
    cout << count << "\n";
}