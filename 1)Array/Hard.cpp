1) Find First Mising Postive

a) TC->O(NlogN)
SC->O(N)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       set<int> s;
       int small=1;
       for(int i:nums)
       {  s.insert(i); //TC->O(logN)
       }
       while(s.find(small)!=s.end())
       {  small++;
       }
        return small;
    }
};

b) TC->O(N)
   SC->O(1)

   We only need to keep track of which ones of the first n positive integers occur in the array. 
   To do this with no extra space, we can treat the array like a boolean array, where sign(arr[i]) 
   indicates whether the i-th positive integer is present or not. First, we replace all non-positive 
   values with n + 1, since we'll only use these indices as storage space. Then, for every one of the 
   first n positive numbers in the array, we turn the value at their corresponding index negative. 
   Finally, all we need to do is check for the first positive value, which will give us the first missing 
   positive. If we find no such index, then all natural numbers up to n are present, so we return n + 1.

   class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) if (nums[i] <= 0) nums[i] = n + 1;
        for (int i = 0; i < n; i++) if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] *= -1;
        for (int i = 0; i < n; i++) if (nums[i] > 0) return i + 1;
        return n + 1;
    }
};
