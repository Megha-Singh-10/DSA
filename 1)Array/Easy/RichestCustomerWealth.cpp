26) 1672. Richest Customer Wealth
/*You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.*/

TC->O(N^2)
SC->O(1)

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi=INT_MIN;
        int m=accounts.size(),n=accounts[0].size();
        int sum=0;
        for(vector<int> i:accounts)
        {
            sum=0;
            for(int j:i)
            {
                sum+=j;
            }
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};