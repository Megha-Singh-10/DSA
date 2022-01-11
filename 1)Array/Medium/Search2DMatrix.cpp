6) 74. Search a 2D Matrix

/*Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.*/

TC-> O(N)
SC-> O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int low=0,high=m*n-1,mid,mid_value;
        while(low<=high)
        {
            mid=(low+high)/2;
            mid_value=matrix[mid/n][mid%n]; //treat matrix as array
            if(mid_value==target) return true;
            else if(mid_value<target) 
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};