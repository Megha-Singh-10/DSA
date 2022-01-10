5) Maximum Subarray sum (no 53)

/* Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.  */

TC-> O(n)
SC->O(1)
class Solution { 
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxi=INT_MIN;
        for(int i:nums)
        {
           sum+=i;  
           sum=max(sum,i);
           maxi=max(maxi,sum);
        }
        return maxi;
        
    }
};
