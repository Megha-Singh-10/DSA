7) 198. House Robber
/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.*/

TC-> O(N)
SC->O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        else if(n==1) return nums[0];
        nums[1]=max(nums[0],nums[1]);                        
        for(int i=2;i<n;i++) 
            nums[i]=max(nums[i]+nums[i-2],nums[i-1]);           
        return nums[n-1];
        
        
        // if(nums.size()==1)return nums[0];
        // vector<int>dp(nums.size());
        // dp[0]=nums[0];
        // dp[1]=max(nums[0],nums[1]);
        // for(int i=2;i<nums.size();i++){
        //     dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        // }
        // return dp[nums.size()-1];
    }
};