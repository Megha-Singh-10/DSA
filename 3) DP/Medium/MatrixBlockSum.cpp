1314. Matrix Block Sum
/* Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

i - k <= r <= i + k,
j - k <= c <= j + k, and
(r, c) is a valid position in the matrix. */

a) TC->O(N*N*N*N)
   SC->O(N*N)

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rl,ru,cl,cu,sum;
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> answer(m,vector<int>(n,0));
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                rl=(i-k<0)?0:(i-k);
                cl=(j-k<0)?0:(j-k);
                ru=(i+k<mat.size()-1)?i+k:mat.size()-1;
                cu=(j+k<mat[0].size()-1)?j+k:mat[0].size()-1;
                sum=0;
                for(int r=rl;r<=ru;r++)
                {
                    for(int c=cl;c<=cu;c++)
                    {
                        sum+=mat[r][c];
                    }
                }
                answer[i][j]=sum;
            }
        }
        return answer;
    }
};

b) TC->O(N*N)
   SC->O(N*N)

class Solution {
    public int[][] matrixBlockSum(int[][] mat, int K) {
        int m = mat.length, n = mat[0].length;
        int[][] sum = new int[m + 1][n + 1]; // sum[i][j] is sum of all elements from rectangle (0,0,i,j) as left, top, right, bottom corresponding
        for (int r = 1; r <= m; r++) {
            for (int c = 1; c <= n; c++) {
                sum[r][c] = mat[r - 1][c - 1] + sum[r - 1][c] + sum[r][c - 1] - sum[r - 1][c - 1];
            }
        }
        int[][] ans = new int[m][n];
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                int r1 = Math.max(0, r - K), c1 = Math.max(0, c - K);
                int r2 = Math.min(m - 1, r + K), c2 = Math.min(n - 1, c + K);
                r1++; c1++; r2++; c2++; // Since `sum` start with 1 so we need to increase r1, c1, r2, c2 by 1
                ans[r][c] = sum[r2][c2] - sum[r2][c1-1] - sum[r1-1][c2] + sum[r1-1][c1-1];
            }
        }
        return ans;
    }
}