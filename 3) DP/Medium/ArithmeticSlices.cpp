1) Arithmetic Slices (#413)

/* An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array. */

TC-> O(N)
SC-> O(N)

class Solution {
public:  
    int numberOfArithmeticSlices(vector<int>& a) {
        if(a.size()<3)
            return 0;
        int res=0,count=1,n=a.size();
        vector<int> d(n);
        d[0]=INT_MAX;
        for(int i=1;i<a.size();i++)
        {    d[i]=a[i]-a[i-1];
        }
        for(int i=2;i<d.size();i++)
        {
            if(d[i]==d[i-1])
                count++;
            else
            {
                if(count>=2)
                {
                    int x=count-1;
                    res+=x*(x+1)/2;
                }
                count=1;
            }
        }
        if(count>=2)
                {
                    int x=count-1;
                    res+=x*(x+1)/2;
                }        
        return res;
    }
};

TC-> O(N)
SC-> O(1)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = nums.size();
        if(n <= 2)  return 0;
        int val=  nums[1] - nums[0];
        int cnt = 1;
        int res = 0;
        for(int i = 2;i<n;i++){
            if((nums[i] - nums[i - 1]) == val){
                cnt++;
            }
            else{
                if(cnt >= 2)    res = res + ((cnt * (cnt - 1)) / 2);
                cnt = 1;
                val = (nums[i] - nums[i - 1]);
            }
        }
        if(cnt >= 2)    res = res + (((cnt - 1) * cnt) / 2);
        return res;
    }
};