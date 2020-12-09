//
//  4179.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 13..
//  Copyright © 2020년 김혜진. All rights reserved.
//

// BFS - if two kinds of information should be calculated

#include <iostream>
#include <queue>

#define x first
#define y second

using namespace std;

int R, C; //row, col
char board[1001][1001]; // # : wall, . : space, J : initial location of the person, F : initial location of fire
int fire[1001][1001];
int person[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    queue<pair<int, int>> fq;
    queue<pair<int, int>> pq;
    
    cin >> R >> C;
    char inputstr[1000];
    
    fill(&fire[0][0], &fire[R][C], -1);
    fill(&person[0][0], &person[R][C], -1);
    
    cin.ignore();
    for(int i = 0; i < R; i++){
        cin.getline(inputstr, C+1);
        for(int j = 0; j < C; j++){
            board[i][j] = inputstr[j];
            if(board[i][j] == 'F'){
                fire[i][j] = 0;
                fq.push({i,j});
            }
            else if(board[i][j] == 'J'){
                person[i][j] = 0;
                pq.push({i,j});
            }
        }
    }

    //bfs for fire
    while(!fq.empty()){
        pair<int, int> cur = fq.front();
        fq.pop();

        
        for(int dir = 0; dir < 4; dir++){
            int nx = dx[dir] + cur.x;
            int ny = dy[dir] + cur.y;
            
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(fire[nx][ny] != -1 || board[nx][ny] == '#') continue;
            
            fire[nx][ny] = fire[cur.x][cur.y] + 1;
            fq.push({nx,ny});
        }
    }

    //bfs for person
    while(!pq.empty()){
        pair<int, int> cur = pq.front();
        pq.pop();

        
        for(int dir = 0; dir < 4; dir++){
            int nx = dx[dir] + cur.x;
            int ny = dy[dir] + cur.y;
        
        ///////////////** IMPORTANT **//////////////////
            if(nx < 0 || nx >= R || ny < 0 || ny >= C){ //this means jihun exited
            
            //in the queue, there are elements in ascending order of distances. So the very front one is the minimum.
                cout << person[cur.x][cur.y] + 1;
                return 0;
            }
        ////////////////////////////////////////////////
            if(person[nx][ny] != -1 || board[nx][ny] == '#') continue;
            if(fire[nx][ny] != -1 && person[cur.x][cur.y] + 1 >= fire[nx][ny]) continue;
            
            person[nx][ny] = person[cur.x][cur.y] + 1;
            pq.push({nx, ny});
        
        }
    }
    cout << "IMPOSSIBLE";
}
