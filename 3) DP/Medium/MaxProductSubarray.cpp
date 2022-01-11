8) 152. Maximum Product Subarray

// Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// A subarray is a contiguous subsequence of the array.

TC-> O(N)
SC-> O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int maxi=nums[0],mini=nums[0],result=nums[0];
        int temp;
        
        for(int i=1;i<nums.size();i++)
        {
            temp=maxi;
            maxi=max(maxi*nums[i],max(mini*nums[i],nums[i]));
            mini=min(temp*nums[i],min(mini*nums[i],nums[i]));
            if(maxi>result)
                result=maxi;
        }
        
        return result;
    }
};