4) Search Insert Position (no 35)

/* Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity. */
TC->O(logn), SC->O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int low=0,high=nums.size(),mid;
        while(low<high)
        {
            mid=(low+high)/2;
            if(nums[mid]>=target)
                high=mid;
            else
                low=mid+1;
        }
        return low;
        
      //  return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    }
};