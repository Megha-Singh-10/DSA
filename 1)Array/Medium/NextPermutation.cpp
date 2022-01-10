5) Next Permutation(#31)

/* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is impossible, it must rearrange it to the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory. */

TC-> O(3N)
SC-> O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j;
        for(i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
                break;
        }
        if(i<0)
            reverse(nums.begin(),nums.end());
        else
        {
            for(j=nums.size()-1;j>=i;j--)
            {
                if(nums[i]<nums[j])
                    break;
            }
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
        }        
    }
};

