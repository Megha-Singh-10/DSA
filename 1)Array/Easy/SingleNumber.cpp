7)  Single number (No 136)//Find the unique number from an array which has all numbers occuring twice except one. 

/* Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.*/

TC->O(N)
SC->O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int i:nums)
            result^=i;
        return result;
    }
};