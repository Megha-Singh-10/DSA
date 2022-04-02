15. 3Sum

/* Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets. */

TC->O(n*n)
SC->o(m)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        if(nums.size()<3)
            return result;
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1])) //avoid duplicate a
          {
            int l=i+1,h=nums.size()-1,sum=0-nums[i];
            while(l<h)
            {               
                    if(nums[l]+nums[h]==sum)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[h]);
                        result.push_back(temp);
                        
                        while(l<h && nums[l]==nums[l+1])
                            l++; // avoid duplicate b by moving b tyo last same element
                        while(l<h && nums[h]==nums[h-1])
                            h--; //avoid duplicate c
                        
                        l++;
                        h--;                        
                    }
                    else if(nums[l]+nums[h]<sum)
                        l++;
                    else
                        h--;
                }
            }
        }
                
        return result;
                                                 
    }
};

b) brute force

SC->o(n^3 log m)
SC->o(m)+o(n)
/* 
  vector<vector<int>> result;
        set<vector<int>> s;
        for(int i=0;i<nums.size()-2;i++)
        {
            for(int j=i+1;j<nums.size()-1;j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0 && i!=j && i!=k && j!=k)
                    {     
                         vector<int> triplet;
                          triplet.push_back(nums[i]);
                          triplet.push_back(nums[j]);
                          triplet.push_back(nums[k]);
                          sort(triplet.begin(),triplet.end());
                          s.insert(triplet);                        
                    }
                }
            }
        }
        for(auto i:s)
            result.push_back(i);
        return result;
                          
                          */