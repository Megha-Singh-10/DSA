75. Sort Colors

/* Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively. */

TC->O(N)
SC->O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=nums.size()-1,k=i;
        while(k<=j)
        {
            if(nums[k]==0)
            {
                swap(nums[k],nums[i]);
                i++;   
                k++;
            }
           else if(nums[k]==2)
            {
                swap(nums[k],nums[j]);
                j--;
            }
            else if(nums[k]==1)
            k++;
        }
    }
};