1486. XOR Operation in an Array
/*
You are given an integer n and an integer start.

Define an array nums where nums[i] = start + 2 * i (0-indexed) and n == nums.length.

Return the bitwise XOR of all elements of nums.*/

TC-> O(2N)
SC-> O(N)

class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>arr(n);
        int ans=0;
        
       for(int i=0;i<n;i++)
           arr[i]=start + 2 * i;
        
        for(auto x:arr)
            ans^=x;
        return ans;
    }
};

 