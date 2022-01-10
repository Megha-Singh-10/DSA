17) Pascal's Triangle (#118)

/* Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

 */
//Display Triangle

TC -> O(N^2)
SC -> O(N^2)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> pascal;
        for(int i=1;i<=numRows;i++)
        {
            vector<int> row(i);
            row[0]=1;
            row[i-1]=1;
            for(int j=1;j<i-1;j++)
            { //if(row[j]!=1)
              row[j]=pascal[i-2][j]+pascal[i-2][j-1];   
            }    
            pascal.push_back(row);
        }
        return pascal;
    }
};