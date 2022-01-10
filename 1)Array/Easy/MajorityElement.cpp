16) Majority Element (#169)

/* Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array. */
a) TC -> O(NlogN)
   SC -> O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int n=nums.size()/2;     
        sort(nums.begin(),nums.end());
        if(nums.size()==1)
            return nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
                count=1;
            else
                count++;
            if(count>n)
            {   cout<<count;
                return nums[i];
            }
        }
        return 0;
    }
};

b) //Boyer-Moore Majority Vote Algorithm

TC -> O(N) 
SC -> O(1)

public class Solution {
    public int majorityElement(int[] num) {

        int major=num[0], count = 1;
        for(int i=1; i<num.length;i++){
            if(count==0){
                count++;
                major=num[i];
            }else if(major==num[i]){
                count++;
            }else count--;
            
        }
        return major;
    }
}
