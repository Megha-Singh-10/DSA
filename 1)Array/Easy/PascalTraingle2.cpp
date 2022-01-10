18) Pascal's Triangle 2 (#119)

/* Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 */
//Display Row

TC -> O(N^2)
SC -> O(N)

class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<int> result;
        if(rowIndex<0)
            return result;
        result.push_back(1);
        for(int i=1;i<=rowIndex;i++)
        {
            result.resize(i+1);
            result[0]=result[i]=1;
            for(int j=i-1;j>0;j--)
            {
                result[j]=result[j]+result[j-1];
            }
        }
        return result;
    }
};