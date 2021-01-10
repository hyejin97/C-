class Solution {
public:
    int minsum[201][201];
    int minPathSum(vector<vector<int>>& grid) {
        //recursive formulation : MS[m][n] = min(MS[m][n-1], MS[m-1][n]) + grid[m][n];
        //basecase : MS[0][0] = grid[0][0]
        dpSum(grid, grid.size()-1, grid[0].size()-1);
        return minsum[grid.size()-1][grid[0].size()-1];
    }
    
    void dpSum(vector<vector<int>>& grid, int m, int n){
        if(m == 0 && n == 0){
            minsum[m][n] = grid[m][n];
            return;
        }
        
        if(m == 0){
            if(!minsum[m][n-1]) dpSum(grid, m, n-1);
            minsum[m][n] = minsum[m][n-1] + grid[m][n];
        }
        else if(n == 0){
            if(!minsum[m-1][n]) dpSum(grid, m-1, n);
            minsum[m][n] = minsum[m-1][n] + grid[m][n];
        }
        else{
            if(!minsum[m-1][n]) dpSum(grid, m-1, n);
            if(!minsum[m][n-1]) dpSum(grid, m, n-1);
            
            minsum[m][n] = min(minsum[m-1][n], minsum[m][n-1]) + grid[m][n];
        }
        
    }
};
