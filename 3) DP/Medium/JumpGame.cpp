9) 55. Jump Game

/*You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.*/

TC-> O(N)
SC->O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>reachable) return false;
            reachable=max(reachable,i+nums[i]);
        }
        return true;
    }
};