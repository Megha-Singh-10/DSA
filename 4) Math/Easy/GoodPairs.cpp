1512. Number of Good Pairs
/* Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j. */

a) TC->O(N)
TC->O(N)

/* This solution first stores the number of occurences of each element in a map. Then if the occurence is more than one it calculates the number of possible combinations of the indices based on the below formula. Then it adds it to the result.
Formula : n(n-1)/2 */
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])!=m.end())
                m[nums[i]]++;
            else
                m[nums[i]]=1;
        }
        for(auto i:m)
        {
            if(i.second>1)
               result+=((i.second-1)*i.second )/2;
        }
        return result;
    }
};


b) TC->O(N^2)
SC-> O(N)
 int numIdenticalPairs(int* nums, int numsSize){
    int count=0;
    int i,j;
    for(i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(i<j)
            {
                if(nums[i]==nums[j])
                    count++;
            }
                
        }
    }
    return count;

}


c) TC->O(N)
SC->O(N+1)

int numIdenticalPairs(int* nums, int numsSize){
    int arr[101]={0},sum=0;
    for(int i=0;i<numsSize;i++)
        sum+=arr[nums[i]]++;
    return sum;
    

}

