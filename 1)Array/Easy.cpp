1) 2Sum  TC-> o(n)  SC->O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> res;
        /*for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=i;
        }*/
        int sum=target;   
        for(int i=0;i<nums.size();i++)
            {
                sum=target-nums[i];
                if(m.find(sum)!=m.end())// && m[sum]!=i)
                {
                    res.push_back(i);
                    res.push_back(m[sum]);
                    return res;
                }
                m[nums[i]]=i;
              }
        return res;
    }
};

2) Remove duplicates from sorted array   
a) TC->O(n^2)   SC ->O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
               
             nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};

b) TC->O(n) SC->O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        if(nums.size()==0) return 0;
        for(int j=1;j<nums.size();j++)
        {
            if(nums[i]!=nums[j])
            {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};

3) Remove Element
TC-> O(n) SC->O(1)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=0;
        for(j=0;j<nums.size();j++)
        {
            if(nums[j]!=val)
            {
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};

4) Search Insert Position
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

5) Maximum Subarray sum
TC-> O(n)
SC->O(1)
class Solution { 
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxi=INT_MIN;
        for(int i:nums)
        {
           sum+=i;  
           sum=max(sum,i);
           maxi=max(maxi,sum);
        }
        return maxi;
        
    }
};

6) Plus One
TC->O(n)
SC->O(1)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        if(digits[n]!=9)
            digits[n]+=1;
        else
        {
            for(int i=n;i>=0;i--)
            {
                if(digits[i]==9)
                    digits[i]=0;
                else
                {   digits[i]++;
                    return digits;
                }
            }
            digits[0]=1;
            digits.push_back(0);
        }
        return digits;
        
    }
};

7)  Single number //Find the unique number from an array which has all numbers occuring twice except one. 

TC->O(N)
SC->O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int i:nums)
            result^=i;
        return result;
    }
};

8) Bull And Sell Stock Best Time 1

a) TC-> O(N^2)
   SC-> O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,j,profit,maxProfit=0;
        int n=prices.size();
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                profit=prices[j]-prices[i];
                if(profit<0)
                     profit=0;
                else
               {
                if (profit>maxProfit)                
                    maxProfit=profit;                
               }              
            }
        }
        return maxProfit;
    }
};

b) TC->O(N)
   SC->O(1)

   class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX,maxProfit=0;
        for(int i:prices)
        {
            minPrice=min(minPrice,i);
            maxProfit=max(maxProfit,i-minPrice);
        }
        return maxProfit;
    }
};

9) Summary Ranges

a) TC-> O(N)
SC-> O(N)

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> results;       
        int low=0,high=0;
        if(nums.size()==1)
        {
           string s=to_string(nums[0]);
            results.push_back(s);
            return results;
        } 
        for(int i=1;i<nums.size();i++)
        {
            string range,s1,s2;
            if(nums[i-1]+1==nums[i])
            {   high=i;                
            }
            else{
                if(high>low){
            s1=to_string(nums[low]);
            s2=to_string(nums[high]);
            range.append(s1);
            range.append("->");
            range.append(s2);
            results.push_back(range);
            low=i;
            high=i;
            }
            else if(nums[low]==nums[high])
            {   string s=to_string(nums[low]); 
                results.push_back(s);
             low=i;
            high=i;
            }
            }
           // range.clear();
        }        
        if(high==nums.size()-1)
        {
            if(high>low){
            string s1=to_string(nums[low]);
            string s2=to_string(nums[high]);
            string range;
            range.append(s1);
            range.append("->");
            range.append(s2);
            results.push_back(range);            
            }
            else if(nums[low]==nums[high])
            {   string s=to_string(nums[low]); 
                results.push_back(s);
            } 
        }
        return results;
    }
};

b) TC-> O(N)
SC-> O(N)

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> f1;
        for(int i = 0;i<nums.size();){
            string f = "";
            f +=(to_string(nums[i]));
            int flag = 0;
            while(i+1<nums.size() && nums[i+1]==nums[i]+1){
                flag = 1;
                i++;
            }
            if(flag){
                f+="->" + to_string(nums[i]);
            }
            i++;
            f1.push_back(f);
        }
        return f1;
    }
};

10) Concatenation Of Arrays

TC-> O(N)
SC-> O(1)

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)        
        {  nums.push_back(nums[i]);
        }
        return nums;
    }
};
