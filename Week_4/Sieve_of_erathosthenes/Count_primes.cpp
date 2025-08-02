// url : 

#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    if(n==1) return 0;
    if(n==0) return 0;
    vector<int> v(n,0);
    int i=2;
    int count = n-2;
    while(i<n){
        if(v[i]!=0){
            count--;
            i++;
            continue;
        }
        for(int j=2;i*j<n;j++){
            v[i*j] = 1;
        }
        i++;
    }
    return count;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << countPrimes(n)<<"\n";
    return 0;
}