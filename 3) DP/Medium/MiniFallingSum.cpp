931. Minimum Falling Path Sum
/* Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1). */

TC-> O(N*N)
SC-> O(1)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),mini;
        for(int i=1;i<n;i++)
            for(int j=0;j<n;j++)
        matrix[i][j]+=min(matrix[i-1][j],min(matrix[i-1][max(0,j-1)],matrix[i-1][min(n-1,j+1)]));
        mini=matrix[n-1][0];
        for(int i=1;i<n;i++)
        {   if(mini>matrix[n-1][i])
              mini=matrix[n-1][i];
        }
        return mini;
        // return *min_element(matrix[n-1].begin(),matrix[n-1].end());
    }
};