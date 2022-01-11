27) 1480. Running Sum of 1d Array

/* Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums. */

TC->O(N)
SC->O(1)

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // vector<int> result;
        // int sum=0;
        // for(int i:nums)
        // {
        //     sum+=i;
        //     result.push_back(sum);
        // }
        // return result;
        
        for(int i=1;i<nums.size();i++)
        nums[i]=nums[i]+nums[i-1];
        return nums;
    }
};