26) Reshape the matrix(#566)

/* In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

  */

TC-> O(N*N)
SC-> O(N*N)

a) class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
       // if(mat[0].size()==r && mat.size()==c)
       //     return mat;
        int m=mat.size();
        int n=mat[0].size();
        if(n*m!=r*c)
            return mat;
       vector<vector<int>> result(r,vector<int>(c));
        int row=0,col=0;       
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {               
                result[row][col]=mat[i][j];
                // col=(col+1)%n;
                // if(col==0)
                //     row++;
                if(col<c-1) col++;
                else if(col==c-1)
                {
                    col=0;
                    row++;
                }
            }            
        }
        return result;
    }
};

b) class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
       //if(mat.size()==r && mat[0].size()==c)
         //   return mat;
        int m=mat.size();
        int n=mat[0].size();
        if(n*m!=r*c)
            return mat;
       vector<vector<int>> result(r,vector<int>(c));
        int row=0,col=0;       
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {               
                //result[row][col]=mat[i][j];
                result[i][j]=mat[row][col];
                col=(col+1)%n;
                if(col==0)
                    row++;                
            }            
        }
        return result;
    }
};

c) matrix traversal in one loop-> matrix[index / width][index % width]

TC-> O(r*c)
SC-> O(r*c)

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if(n*m != r*c)return mat;
        vector<vector<int>>v(r, vector<int>(c,0));
        for(int i = 0; i<r*c; i++)        
            v[i/c][i%c] = mat[i/n][i%n];
        return v;
    }


