29) 1394. Find Lucky Integer in an Array
/* Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1. */

TC->O(N^2)
SC->O(N)

class Solution {
public:
    int findLucky(vector<int>& nums) {
        //1
        // int count=1;
        // sort(nums.begin(),nums.end());
        // for(int i=nums.size()-1;i>0;i--)
        // {
        //     if(nums[i]==nums[i-1])
        //     {
        //         count++;              
        //     }
        //     else //if(nums[i]!=nums[i-1])
        //     {
        //         if(count==nums[i])
        //             return nums[i];
        //         else
        //             count=1;
        //     }
        // }
        // if(nums[0]==count)
        //     return nums[0];
        // return -1;
        
        //2
        // unordered_map<int,int> m;
        // for(auto i:nums)
        //    m[i]++;
        // int maxi=INT_MIN;
        // for(auto i:m)
        // {    if(i.first==i.second)
        //         maxi=max(maxi,i.first);
        // }
        // return maxi==INT_MIN?-1:maxi;
        
        //3
        int a[501]={0};
        for(int i:nums)
            a[i]++;
        for(int i=500;i>0;i--)
        {
            if(a[i]==i)
                return i;
        }
        return -1;
    }
};

 