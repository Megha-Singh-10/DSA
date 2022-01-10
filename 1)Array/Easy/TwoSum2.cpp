15) Two Sum II - Input array is sorted(#167)

/* Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice. */

TC -> O(N)
SC -> O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        vector<int> result;
        int low=0,high=a.size()-1;
        while(low<high)
        {
            if(a[low]+a[high]==target)
            {
                result.push_back(low+1);
                result.push_back(high+1);
                break;
            } 
            else if(a[low]+a[high]<target)
                low++;
            else if(a[low]+a[high]>target)
                high--;               
        }        
        return result;
    }
};