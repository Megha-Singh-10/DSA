1) 9. Palindrome Number
/* Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.*/

TC->O(N)
SC->O(1)

class Solution {
public:
    bool isPalindrome(int x) {
        int y=x,rem;
        long res=0;
        if(x<0) return false;
        while(x!=0)
        {
            rem=x%10;
            res=res*10+rem;
            x=x/10;
        }        
        if(y==res) return true;
        else return false;
        return true;
    }
};