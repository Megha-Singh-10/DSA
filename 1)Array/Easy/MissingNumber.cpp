11) Missing Number (range [0, n]) (#268)
 
 /* Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array. */
 
 TC-> O(N)
 SC->O(1)
 
 class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int result=n*(n+1)/2;
        int sum=0;
        for(int i:nums)
            sum+=i;
        return result-sum;
    }
};