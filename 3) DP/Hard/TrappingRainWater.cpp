2. (Problem 42) Trapping Rain Water

TC-> O(N)
SC->O(1)
/* Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int leftmax=0,rightmax=0;
        long int res=0;
        
        while(l<=r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>=leftmax)
                    leftmax=height[l];
                else
                    res+=leftmax-height[l];
                l++;
            }
            else
            {
                if(height[r]>=rightmax)
                    rightmax=height[r];
                else
                    res+=rightmax-height[r];
                r--;
            }
        }
        return res;
    }
};