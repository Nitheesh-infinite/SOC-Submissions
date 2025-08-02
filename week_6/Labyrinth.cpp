// // url : https://cses.fi/problemset/task/1193

// #include<bits/stdc++.h>
// using namespace std;

// int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};
// string dir[] = {"R","L","U","D"};
// vector<string> paths;
// char a[1000][1000];

// void search(int start_x,int start_y,int end_x,int end_y,string s,int n,int m){
//     for(int i = 0;i<4;i++){
//         int next_x = start_x + dx[i],next_y = start_y + dy[i];
//         if( next_x >=0 && next_x<n &&next_y >= 0 && next_y<m){
//             if(a[next_x][next_y] != '#' && a[next_x][next_y] != 'A'){
//                 s += dir[i];
//                 if( next_x == end_x && next_y == end_y){
//                     paths.push_back(s);
//                     break;
//                 }
//                 else search(next_x,next_y,end_x,end_y,s,n,m);
//             }
            
//         }
//     }
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n,m;
//     cin >>n>> m;
//     int x,y,c,d;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin >> a[i][j];
//             if(a[i][j] == 'A' ) {x= i;y=j;}
//             else if( a[i][j] == 'B'){ c = i;d=j;}
//         }
//     }
//     string s = "";
//     search(x,y,c,d,s,n,m);
//     if(paths.empty()) {cout << "NO" <<"\n"; return 0;}
//     int min = 1e6; 
//     string min_string;
//     for( auto x: paths){
//         if(min > x.size()) min_string = x;
//     }
//     cout << "YES" << "\n" << min<< "\n" << min_string << "\n";

// }

#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pii pair<int, int>
pii parent[1000][1000];
int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};
char dir[] = {'D','U','R','L'};
bool visited[1000][1000];
char grid[1000][1000];
char mov_dir[1000][1000];

bool isvalid(int x, int y,int n,int m) {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && !visited[x][y]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >>n>> m;
    int x,y,c,d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >>grid[i][j];
            if( grid[i][j] == '#') visited[i][j] = true;
            else if(grid[i][j] == 'A' ) {x= i;y=j;}
            else if( grid[i][j] == 'B'){ c = i;d=j;}
        }
    }
    pii start = {x,y};
    queue<pii> q;
    q.push({x,y});
    visited[x][y] = true;
    bool found = false;
    while(!q.empty()){
        x = q.front().F;
        y = q.front().S;
        q.pop();
        if(x ==c&&y == d){
            found = true;
            break;
        }
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isvalid(nx,ny,n,m)){
                visited[nx][ny] = true;
                parent[nx][ny] = {x,y};
                mov_dir[nx][ny] = dir[i];
                q.push({nx,ny});
            }
        }
    }

    if(!found) {cout << "NO" <<"\n"; return 0;}
    string path;
    pii current = {c,d};
    while( current != start ){
        char d = mov_dir[current.F][current.S];
        path += d;
        current = parent[current.F][current.S];
    }
    reverse(path.begin(),path.end());
    cout << "YES" << "\n" << path.size() << "\n" << path << "\n";
    return 0;
        
}