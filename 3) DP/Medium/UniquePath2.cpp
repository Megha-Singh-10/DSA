63. Unique Paths II
/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid. */

TC->O(N^2)
SC->O(1)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        bool row0=false,col0=false;
        if(m==1 && n==1)
            return !obstacleGrid[0][0];
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)
            return 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                    obstacleGrid[i][j]=-1;
            }
        }
        for(int j=0;j<n;j++)
        {  if(obstacleGrid[0][j]==-1)
               row0=true;
           if(row0)
             obstacleGrid[0][j]=0;
           else
               obstacleGrid[0][j]=1;
        }
         for(int i=0;i<m;i++)
         {  if(obstacleGrid[i][0]==-1)
              col0=true;
           if(col0)
               obstacleGrid[i][0]=0;
           else
               obstacleGrid[i][0]=1;
         }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==-1)
                    obstacleGrid[i][j]=0;
                else
                    obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
               // obstacleGrid[i][j]=(obstacleGrid[i-1][j]==-1?0:obstacleGrid[i-1][j])+
               //                    (obstacleGrid[i][j-1]==-1?0:obstacleGrid[i][j-1]);
            }
        } 
        return obstacleGrid[m-1][n-1];
    }
};

 