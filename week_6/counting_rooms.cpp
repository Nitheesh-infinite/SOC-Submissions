// url : https://cses.fi/problemset/task/1192

#include<bits/stdc++.h>
using namespace std;

bool visited[1000][1000];
int dx[] = {1,-1,0,0}, dy[] = {0,0,-1,1};

void search(int x,int y,int N,int M){
    visited[x][y] = true;
    for(int i = 0;i < 4;i++){
        if(x+dx[i] >=0 && x+dx[i] < N && y+dy[i] >= 0 && y+dy[i] < M && !visited[x+dx[i]][y+dy[i]]) search(x+dx[i],y+dy[i],N,M);
    }
}

int main(){
    int N,M;
    cin >> N >>M;
    char c;
    for(int i = 0;i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> c;
            if( c == '#' ) visited[i][j] = true;
            else visited[i][j] = false;
        }
    }
    int rooms = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j]) {
                search(i,j,N,M);
                rooms++;
            }
        }
    }
    cout << rooms << "\n";
}