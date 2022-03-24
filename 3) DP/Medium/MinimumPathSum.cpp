64. Minimum Path Sum
/* Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time. */

TC->O(N*N+2*N)
SC->O(1)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
          int m=grid.size(),n=grid[0].size();
        for(int j=1;j<n;j++)
            grid[0][j]+=grid[0][j-1];
        for(int i=1;i<m;i++)
            grid[i][0]+=grid[i-1][0];        
        for(int i=1;i<grid.size();i++)
        {
            for(int j=1;j<grid[0].size();j++)
            {
               grid[i][j]+=min(grid[i][j-1],grid[i-1][j]); 
            }
        }
        return grid[m-1][n-1];
    }
};