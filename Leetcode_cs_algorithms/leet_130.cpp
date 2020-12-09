//
//  leet_130.cpp
//  codingtestprep
//
//  Created by 김혜진 on 2020. 11. 14..
//  Copyright © 2020년 김혜진. All rights reserved.
//


//130. Surrounded Regions


class Solution {
public:
    //if we do dfs from inner zeros and check whether it reseaches border lines, it will be complicated problem. In this way we have to traverse all the connected group and then check whether there is any element on the border. Unless, if we stop traversing when reached border but havn't travered all the connected items, as we set traversed items as visitied and never look at them again, the remaining items can cause a lot of edge cases. However, the former way is unefficient.
    //Therefore, we instead start from the border line and set all the connected items as '#' and after doing dfs at the whole matrix convert those items which is still 'O' to 'X'
    vector<vector<int>> visited;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    void solve(vector<vector<char>>& board) {
        if(board.size() < 1) return;
        
        int m = board.size();
        int n = board[0].size();
        
        //initialize visited vector
        for(int i = 0; i < m; i++){
            visited.push_back({});
            for(int j = 0; j < n; j++){
                visited[i].push_back(0);
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                //boarder & 'O'
                if(i == 0 || i == m - 1 || j == 0 || j == n-1){
                    if(board[i][j] == 'O')
                        dfs(board, i, j, m, n);
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '*') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n){
        visited[i][j] = 1;
        board[i][j] = '*';
        
        for(int k = 0; k < 4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            
            //outside of the range
            if(nx < 0 || nx > m - 1 || ny < 0 || ny > n-1) continue;
            
            if(visited[nx][ny] != 1 && board[nx][ny] == 'O') dfs(board, nx, ny, m, n);
        }
        
        
    }
};
