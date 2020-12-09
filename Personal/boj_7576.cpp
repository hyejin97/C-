//
//  7576.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 13..
//  Copyright © 2020년 김혜진. All rights reserved.
//

// bfs - multiple starting points

#include <iostream>
#include <queue>

#define x first
#define y second

using namespace std;

int N, M; //row, col
int board[1002][1002];
int ripe[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    cin >> M >> N;
    
    //initialize to -1
    fill(&ripe[0][0], &ripe[N][M], -1);
    fill(&board[0][0], &board[N][M], -1);
    
    int val;
    queue<pair<int, int>> q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> val;
            board[i][j] = val;
            
            //////////**IMPORTANT**////////////
            // put all the starting points to the queue and then start bfs
            if(val == 1){
                ripe[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        
        pair<int, int> cur = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            
            if(nx < 0 || nx > N || ny < 0 || ny > M) continue;
            if(ripe[nx][ny] != -1 || board[nx][ny] == -1) continue;
            
            ripe[nx][ny] = ripe[cur.x][cur.y] + 1;
            q.push({nx, ny});
        }
    }

    int minday = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(ripe[i][j] == -1 && board[i][j] != -1){
                cout << -1 << '\n';
                return 0;
            }
            minday = max(minday, ripe[i][j]);
        }
    }
    cout << minday << '\n';
}

