1822. Sign of the Product of an Array
/* There is a function signFunc(x) that returns:

1 if x is positive.
-1 if x is negative.
0 if x is equal to 0.
You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product). */

a) TC->O(N)
SC->O(1)

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count=0;
        for(int i:nums)
        {
            if(i==0)
                return 0;
            else if(i<0)
                count++;
        }
        return count%2==0 ? 1: -1;
    }
};

b) /* Same TC and SC but little faster as no % is used */

public int arraySign(int[] nums) {
        int sign = 1; 
        for (int n : nums) {
            if (n == 0) {
                return 0; 
            } 
			if (n < 0) {
                sign = -sign; 
            }
        }
        return sign; 
    }