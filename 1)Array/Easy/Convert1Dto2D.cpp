20) Convert 1D Array Into 2D Array (#2022)
/* You are given a 0-indexed 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) array with m rows and n columns using all the elements from original.

The elements from indices 0 to n - 1 (inclusive) of original should form the first row of the constructed 2D array, the elements from indices n to 2 * n - 1 (inclusive) should form the second row of the constructed 2D array, and so on.

Return an m x n 2D array constructed according to the above procedure, or an empty 2D array if it is impossible. */

a) TC-> O(N^2)
SC-> O(N^2)

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> newArray(m,vector<int>(n));
        vector<vector<int>> no; //to return empty array
        if(original.size()!=m*n)
            return no;
        int k=0;
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               newArray[i][j]=original[k++];
           }
       }
        return newArray;
    }
};

b) TC-> O(N)
SC-> O(N^2)

for(int i=0;i<original.length;i++)
		result[i/n][i%n] = original[i];