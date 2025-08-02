// url : https://codeforces.com/contest/1102/problem/D

// too much messed up
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n;
//     cin >> n;
//     string s;
//     cin>> s;
//     int n0 = 0,n1=0,n2=0;
//     vector<vector<int>> indices(3);
//     vector<vector<int>> unwanted_indices(3);
//     vector<vector<int>> final_indices(3);
//     for(int i=0;i<n;i++){
//         if(s[i] == '0'){ n0++;
//             indices[0].push_back(i);
//             if(n0 > n/3) unwanted_indices[0].push_back(i);}
//         else if(s[i] == '1') { n1++;
//         indices[1].push_back(i);
//         if(n1 > n/3) unwanted_indices[0].push_back(i);}
//         else {n2++;
//             indices[2].push_back(i);
//             if(n2 > n/3) unwanted_indices[2].push_back(i); }
//     }
//     int k = 0;
//     if(n0 <= n/3 && n1 <= n/3){
//         int i;
//         for(i=0;i<n/3-n0;i++){
//             indices[0].push_back(indices[2][i]);
//         }
//         for(i=0;i<n/3-n1;i++){
//             indices[1].push_back(indices[2][i+n/3-n0]);
//         }
//     }
//     else if(n0 <= n/3 && n1 >= n/3 && n2 >= n/3){
//         for(int i=0;i<n1 - n/3;i++){
//             indices[0].push_back(indices[1][i]);
//         }
//         for(int i=0;i<n2-n/3;i++){
//             indices[0].push_back(indices[2][i]);
//         }
//     }
//     else if (n0 <= n/3 && n1 >= n/3 && n2 <= n/3){
//         for(int i=0;i<n/3 - n0;i++){
//             indices[0].push_back(indices[1][i]);
//         }
//     }
//     else if(n0 >= n/3 && n1 >= n/3 ){
//         k = 1;
//     }
//     else if(n0 >= n/3 && n1 <= n/3 && n2 >= n/3){
//         for(int i=0;i<n/3-n1-n0+n/3;i++){
//             indices[1].push_back(indices[2][i]);
//         }
//         for(int i=0;i<n0-n/3;i++){
//             indices[1].push_back(unwanted_indices[0][i]);
//         }
//     }
//     else if(n0 >= n/3 && n1 <= n/3 && n2 <= n/3){
//         for(int i=0;i<n/3-n1;i++){
//             indices[1].push_back(unwanted_indices[0][i]);
//         }
//     }
//     vector<int> v(n,2);
//     for()

// }