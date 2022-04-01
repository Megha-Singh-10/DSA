287. Find the Duplicate Number
/* Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.*/

//DSA Sheet Day1 Problem 1

a) TC->O(N)
SC-> O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0],fast=nums[0];
        do
        {
           slow=nums[slow];
           fast=nums[nums[fast]];
        }while(slow!=fast); //tortoise method
        fast=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow; //or fast
    }
};