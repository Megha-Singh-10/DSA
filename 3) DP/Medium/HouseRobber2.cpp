6) 213. House Robber II
/* You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police. */

TC-> O(2N)
SC->O(N)

class Solution {
public:
    int rob(vector<int>& nums) {       
        int n=nums.size();
        int dp[n],dp2[n]; 
         if(n==0) return 0;
        else if(n==1) return nums[0];  
       if(nums.size()==2)
           return max(nums[0],nums[1]);              
     //   dp[0]=nums[0];
        dp[1]=nums[1]; //exclude 0,inc n
        dp[2]=max(nums[1],nums[2]);         
        dp2[0]=nums[0]; //exclude n, inc 0
        dp2[1]=nums[0];        
        for(int i=3;i<n;i++)
        {                                  
             dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        } 
        for(int i=2;i<n-1;i++)
        {                                  
             dp2[i]=max(dp2[i-1],nums[i]+dp2[i-2]);
        }         
        return max(dp[n-1],dp2[n-2]);
       
        // if(nums.size()==1)        
        //     return nums[0];
        // if(nums.size()==2)
        //     return max(nums[0],nums[1]);
        // vector<int >dp(nums.size(),0);
        // vector<int >dp2 (nums.size(),0);
        // // flag=false;
        // dp[0]=dp[1]=nums[0];
        // dp2[1]=nums[1];
        // dp2[2]=max(nums[2],nums[1]);
        // for(int i=2;i<nums.size()-1;i++        
        //     dp[i]= max(nums[i]+dp[i-2],dp[i-1]);            
        // for(int i=3;i<nums.size();i++)        
        //     dp2[i]= max(nums[i]+dp2[i-2],dp2[i-1]);            
        // return max(dp[nums.size()-2],dp2[nums.size()-1]);
    }
};