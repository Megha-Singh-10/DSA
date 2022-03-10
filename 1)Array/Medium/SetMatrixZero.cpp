73. Set Matrix Zeroes
/* Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place. */
a) TC-> O(3*N*N)
SC-> O(2N)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row;
        vector<int> col;        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    row.push_back(i);
                    col.push_back(j);
                }                
            }   
        }
        for(int i:row)
        {
            for(int j=0;j<matrix[0].size();j++)
                matrix[i][j]=0;
        }
        for(int j:col)
        {
            for(int i=0;i<matrix.size();i++)
                matrix[i][j]=0;
        }
    }
};

b) TC-> O(3*N*N+O(2N))
SC->O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col=matrix[0][0];
        for(int i=matrix.size()-1;i>0;i--)
        {
            for(int j=matrix[0].size()-1;j>0;j--)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        if(matrix[0][0]==0)
        {
         for(int i=1;i<matrix.size();i++)
             matrix[i][0]=0;
         for(int j=1;j<matrix[0].size();j++)
             matrix[0][j]=0;
        }
        
        for(int i=1;i<matrix.size();i++)
        {
           if(matrix[i][0]==0)
           {  
               col=0;
               for(int j=1;j<matrix[0].size();j++)
                 matrix[i][j]=0;
           }
        }
        for(int j=1;j<matrix[0].size();j++)
            if(matrix[0][j]==0)
            {col=0;
             for(int i=1;i<matrix.size();i++)
                       matrix[i][j]=0;
            }
        matrix[0][0]=col;
    
    }
};