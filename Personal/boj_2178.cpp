//
//  2178.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 11..
//  Copyright © 2020년 김혜진. All rights reserved.
//

//bfs - measuring distance problem in multi-dimentional arrays

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <queue>

#define x first
#define y second

using namespace std;

int N, M;// row, col
int dist[102][102];
int board[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    cin >> N >> M;
    char row[102];
    
    cin.ignore();
    for(int i = 0; i < N; i++){
        cin.getline(row, M + 1);
        
        for(int j = 0; j < M; j++){
            board[i][j] = row[j] - '0';
        }
    }
    
    queue<pair<int, int>> q;
    fill(&dist[0][0], &dist[N][M], -1);
    
    dist[0][0] = 1;
    q.push({0,0});
    
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        //cout << '(' << cur.x << ',' << cur.y << ')' << '\n';
        
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
        
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        
            if(dist[nx][ny] != -1 || board[nx][ny] == 0) continue;
            
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            q.push({nx, ny});
        }
    }
    
    cout << dist[N-1][M-1] << '\n';

}
