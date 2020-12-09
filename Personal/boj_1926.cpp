//
//  1926.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 11..
//  Copyright © 2020년 김혜진. All rights reserved.
//

//bfs - flood fill example
#include <iostream>
#include <queue>

#define x first
#define y second

using namespace std;

int cnt = 0;
int n, m; //height, width
int maxsize = 0;
int board[502][502];
int visited[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(queue<pair<int, int>>* q, int i, int j){
    int cursize = 1;
    while(!q->empty()){
        
        pair<int, int> cur = q->front();
        q->pop();
        
        //cout << '(' << cur.x << ',' << cur.y << ')' << '\n';
        
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            
            //if index out of range
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            //if already visited or not 1
            if(visited[nx][ny] || board[nx][ny] == 0) continue;
            
            visited[nx][ny] = 1;
            q->push({nx,ny});
            cursize++;
        }
        
    }
    maxsize = max(maxsize, cursize);
    return;
}

int main(){
    int val;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> val;
            board[i][j] = val;
        }
    }
    

    //find the start point
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 0 || visited[i][j] == 1) continue;
            //make new queue for bfs
            queue<pair<int, int>> q;
            
            //set the start point
            visited[i][j] = 1;
            q.push({i,j});
            
            bfs(&q, i, j);
            cnt++;
        }
    }
    
    cout << cnt << '\n';
    cout << maxsize << '\n';

}
