13a) Climbing Stairs(1 or 2 steps)(#70)

/* You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? */

TC-> O(N)
SC->O(1)

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(2);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
            dp[i%2]=dp[0]+dp[1];//dp[i]=dp[i-1]+dp[i-2] SC->O(N)
        return dp[n%2];
    }
};

13b) Climbing Stairs (1 or 3 or 5 steps)

dp[i]=dp[i-1]+dp[i-3]+dp[i-5];

Generalize for any number of steps at a time

TC-> O(N*M) //where M is the size of steps array
SC->O(N)

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            int count=0;
            for(int j:steps)
            {
                if(i-j>=0)
                count+=dp[i-j];
            }
            dp[i]=count;
        }
        return dp[n];
    }
}; 
