1) 2011. Final Value of Variable After Performing Operations
/* There is a programming language with only four operations and one variable X:

++X and X++ increments the value of the variable X by 1.
--X and X-- decrements the value of the variable X by 1.
Initially, the value of X is 0.

Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations. */

TC-> O(N)
SC->O(1)

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(string s:operations)
        {
            if(s[1]=='-')
                x--;
            else if(s[1]=='+')
                x++;
        }
        return x;
    }
};