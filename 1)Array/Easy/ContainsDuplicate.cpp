12) Contains Duplicate (#217)

/* Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct. */

a) TC->O(NlogN) //TC->O(N) if unordered_set is used
SC->O(N)

#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();        
    }
};

b) TC->O(NlogN)
SC->O(1)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
                return true;
        }
        return false;
    }
};
