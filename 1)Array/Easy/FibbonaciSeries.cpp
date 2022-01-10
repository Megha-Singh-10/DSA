14) Fibbonaci Series (#509)

/* The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n). */

TC->O(N)
SC->O(1)

class Solution {
public:
    int fib(int n) {
        int dp[2];
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
            dp[i%2]=dp[0]+dp[1];
        return dp[n%2];
    }
};