// url : https://cses.fi/problemset/task/3314

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>> n;
    vector<ll> heights(n);
    int max = 0;
    vector<int> max_height;
    for(int i=0;i<n;i++){
        cin >> heights[i];
        if(max < heights[i]) max = heights[i];
    }
    for(int i=0;i<n;i++){
        if(heights[i] == max) max_height.push_back(i);
    }
    vector<int> v;
    v.push_back(max_height[0]-0);
    int k = max_height.size();
    for(int i=1;i<k;i++){
        v.push_back(max_height[i]-max_height[i-1]-1);
    }
    v.push_back(n-1-max_height[k-1]);
    max = 0;
    for(int x : v){
        if(max < x) max = x;
    }
    cout << max << "\n";
}