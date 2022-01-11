10) 45. Jump Game II

/*Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.*/

TC-> O(N)
SC-> O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        int curReach=0,maxReach=0,jumps=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(i+nums[i]>maxReach)
                maxReach=i+nums[i];
            if(i==curReach)
            {
                jumps++;
                curReach=maxReach;
            }
        }
        return jumps;
    }
};