1) 1137. N-th Tribonacci Number
/*The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.*/

TC->O(N)
SC->O(1)

class Solution {
public:
    int tribonacci(int n) {
        int dp[3];
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        
        for(int i=3;i<=n;i++)
            dp[i%3]=dp[0]+dp[1]+dp[2];
        
        return dp[n%3];
    }
};