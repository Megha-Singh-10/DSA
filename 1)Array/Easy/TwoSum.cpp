1) Two Sum (Problem 1)

/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.*/

TC-> o(n)  SC->O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> res;
        /*for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=i;
        }*/
        int sum=target;   
        for(int i=0;i<nums.size();i++)
            {
                sum=target-nums[i];
                if(m.find(sum)!=m.end())// && m[sum]!=i)
                {
                    res.push_back(i);
                    res.push_back(m[sum]);
                    return res;
                }
                m[nums[i]]=i;
              }
        return res;
    }
};