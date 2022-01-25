2119. A Number After a Double Reversal
/* Reversing an integer means to reverse all its digits.

For example, reversing 2021 gives 1202. Reversing 12300 gives 321 as the leading zeros are not retained.
Given an integer num, reverse num to get reversed1, then reverse reversed1 to get reversed2. Return true if reversed2 equals num. Otherwise return false. */

TC->O(1)
SC->O(1)

class Solution {
public:
    bool isSameAfterReversals(int num) {
    if(num==0)
            return true;
     if(num%10==0)   
         return false;
        else
            return true;
    }
};

/* 1 line solution same */

return num == 0 || num % 10;