1431. Kids With the Greatest Number of Candies
/* There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.*/

TC->O(2N)
SC->O(N)

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=INT_MIN;
        vector<bool> result;
        for(int i=0;i<candies.size();i++)
        {    if(candies[i]>maxi)            
              maxi=candies[i];                         
            candies[i]+=extraCandies;
         // cout<<candies[i]<<" ";
        }
        // cout<<"\n"<<maxi;
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]<maxi)
                result.push_back(false);
            else
                result.push_back(true);
        }
        return result;
    }
};