class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<int>> visited;
        
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0 ; i < m; i++){
            visited.push_back({});
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) q.push({i, j});
                visited[i].push_back(0);
            }
        }
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(grid[nx][ny] == 1 && visited[nx][ny] == 0){
                    q.push({nx, ny});
                    grid[nx][ny] = 2;
                    visited[nx][ny] = visited[x][y] + 1;
                }
            }
        }
        int duration = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) return -1;
                if(visited[i][j] > duration) duration = visited[i][j];
            }
        }
        return duration;
    }
};
