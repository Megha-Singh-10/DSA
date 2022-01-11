4) 918. Maximum Sum Circular Subarray
/*Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.*/

TC->O(N)
SC->O(1)

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum=0,tempMaxSum=0,tempMinSum=0,minSum=INT_MAX,maxSum=INT_MIN;
        for(int i:nums)
        {
            totalSum+=i;
            
            tempMaxSum+=i;
            tempMinSum+=i;
            
            minSum=min(tempMinSum,minSum);
            maxSum=max(tempMaxSum,maxSum);
            
            if(tempMaxSum<0) tempMaxSum=0;
            if(tempMinSum>0) tempMinSum=0;
        }
        if(minSum==totalSum)
            return maxSum;
        return max(maxSum,totalSum-minSum);
    }
};