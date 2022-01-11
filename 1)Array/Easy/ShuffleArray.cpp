28) 1470. Shuffle the Array
/* Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].*/

TC->O(N)
SC->O(N)

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // int temp;
        // for(int i=0,j=i+n;i<nums.size()/2;i++,j++)
        // {
        //     temp=j;
        //     for(int k=j;k>=i+1;k--)
        //       nums[k]=nums[k-1];
        //     nums[i+1]=temp;
        // }
        // return nums;
        
        vector<int> result;
        for(int i=0,j=i+n;i<nums.size()/2;i++,j++)
        {
            result.push_back(nums[i]);
            result.push_back(nums[j]);
        }
        return result;
    }
};