//
//  15683.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 24..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

#define x first
#define y second

int board[10][10];
int visited[10][10];
int N, M; //N : row, M : col
int mincnt = 100; //# of available spaces

//right, up, left, down
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<pair<int,int>> v;

void monitor(int nx, int ny, int dir){
    dir %= 4;
    while(1){
        nx += dx[dir];
        ny += dy[dir];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny] == 6) return;
        if(visited[nx][ny] != 0) continue;
        visited[nx][ny] = 7;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] != 0){
                if(board[i][j] != 6){
                    v.push_back({i,j});
                }
            }
        }
    }
    //consider all possible directions of "cnt" number of cctvs
    //using quaternary numbering
    // index : [0][1][2][3][4][5][ ... ][k] -> k number of cameras
    //  .
    //  .
    //  .
    // 4^k number of rows, each space has 4 directions(0-3).
    for(int brut = 0; brut < (1 << (2*v.size())); brut++){
        int tmp = brut;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                visited[i][j] = board[i][j];
            }
        }
        for(int cam = 0; cam < v.size(); cam++){
            int dir = tmp % 4;
            tmp = tmp / 4;
            
            int xs = v[cam].x;
            int ys = v[cam].y;
        
            if(board[xs][ys] == 1){
                monitor(xs, ys, dir);
            }
            else if(board[xs][ys] == 2){
                monitor(xs, ys, dir);
                monitor(xs, ys, dir + 2);
            }
            else if(board[xs][ys] == 3){
                monitor(xs, ys, dir);
                monitor(xs, ys, dir + 1);
            }
            else if(board[xs][ys] == 4){
                monitor(xs, ys, dir);
                monitor(xs, ys, dir + 1);
                monitor(xs, ys, dir + 2);
            }
            else{
                monitor(xs, ys, dir);
                monitor(xs, ys, dir + 1);
                monitor(xs, ys, dir + 2);
                monitor(xs, ys, dir + 3);
            }
        }
        int cnt_tmp = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(visited[i][j] == 0) cnt_tmp++;
            }
        }
        mincnt = min(mincnt, cnt_tmp);
    }
    cout << mincnt;
}
