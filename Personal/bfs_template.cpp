//
//  bfs.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 11..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

#define x first
#define y second

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
    {1,0,0,0,1,0,0,0,0,0},
    {1,1,1,0,1,0,0,0,0,0},
    {1,1,0,0,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0} };

bool visited[502][502];
int n = 7, m = 10; //n : row, m : col
int dx[4] = {1,0,-1,0}; //check up and down
int dy[4] = {0, 1, 0, -1}; //check left and right

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<pair<int, int>> q;
    
    //initialization - set (0,0) to the start line
    visited[0][0] = 1;
    q.push({0,0});
    
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        
        cout << '(' << cur.x << ',' << cur.y << ')' << '\n';
        
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            
            //point 1 : avoid referencing index out of the range
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            //point 2 : one of the key conidtion for bfs.
            if(visited[nx][ny] || board[nx][ny] != 1) continue;
            
            //point 3 : mark as visited when pushing into pairs
            visited[nx][ny] = 1;
            q.push({nx, ny});
            
            
        }
    }
}




