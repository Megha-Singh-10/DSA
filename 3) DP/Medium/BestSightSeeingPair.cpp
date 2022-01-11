3) 1014. Best Sightseeing Pair
/*
You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.*/

TC->O(N)
SC-> O(1)

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
    int maxi=values[0]+0;
        int res=INT_MIN;
        
        for(int i=1;i<values.size();i++)
        {
            res=max(res,maxi+values[i]-i);
            maxi=max(maxi,values[i]+i);
        }
    return res;     
  }
};