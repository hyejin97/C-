//
//  leet_200.cpp
//  C++
//
//  Created by 김혜진 on 2020. 10. 1..
//  Copyright © 2020년 김혜진. All rights reserved.
//

//200. number of islands
class Solution {
    int count = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    void bfs(int i, int j, vector<vector<int>>& visited, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        visited[i][j] = 1;
        q.push({i, j});
        
        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                
                if(nx < 0 || nx >= visited.size() || ny < 0 || ny >= visited[0].size() ) continue;
                if(visited[nx][ny] || grid[nx][ny] == '0') continue;
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        vector<vector<int>> visited(grid.size());
        for(int i = 0; i < grid.size(); i++)
            visited[i] = vector<int>(grid[i].size());
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    bfs(i, j, visited, grid);
                    count++;
                }
            }
        }
        return count;
    }
    
    
    
};
