1365. How Many Numbers Are Smaller Than the Current Number
/* Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.*/

a) 
TC->O(N)
SC->O(N)

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> answer;
        int i, j;
        int count[101] = {0, 0, 0};
        for(i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        for(i = 1; i < 101; i++) {
            count[i] += count[i - 1];
        }
        for(i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)
                answer.push_back(0);
            else
                answer.push_back(count[nums[i] - 1]);
                
        }
        return answer;
    }
};

b) TC->O(NlogN)
SC->O(2N)

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]

snum=sorted array(nums) = [1,2,2,3,8]
mp=(snum[i],i) (tail to head insertion in map)
8 4
3 3
2 2=>1
1 0

nums[i]=maps[nums[i]]
nums=[4,0,1,1,3]=output

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
    
        map<int,int> mp;    
        int n=nums.size();
        vector<int> snum=nums;
        
        sort(snum.begin(),snum.end());
        for(int i=n-1;i>=0;i--)
            mp[snum[i]]=i;
        
        for(int i=0;i<n;i++)
            nums[i]=mp[nums[i]];
        
        return nums;
    }
};