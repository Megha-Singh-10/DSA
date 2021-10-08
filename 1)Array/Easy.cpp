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

11) Missing Number (range [0, n])
 
 TC-> O(N)
 SC->O(1)
 
 class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int result=n*(n+1)/2;
        int sum=0;
        for(int i:nums)
            sum+=i;
        return result-sum;
    }
};

12) Contains Duplicate

a) TC->O(NlogN) //TC->O(N) if unordered_set is used
SC->O(N)

#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();        
    }
};

b) TC->O(NlogN)
SC->O(1)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
                return true;
        }
        return false;
    }
};

13a) Climbing Stairs(1 or 2 steps)

TC-> O(N)
SC->O(1)

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(2);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
            dp[i%2]=dp[0]+dp[1];//dp[i]=dp[i-1]+dp[i-2] SC->O(N)
        return dp[n%2];
    }
};

13b) Climbing Stairs (1 or 3 or 5 steps)

dp[i]=dp[i-1]+dp[i-3]+dp[i-5];

Generalize for any number of steps at a time

TC-> O(N*M) //where M is the size of steps array
SC->O(N)

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            int count=0;
            for(int j:steps)
            {
                if(i-j>=0)
                count+=dp[i-j];
            }
            dp[i]=count;
        }
        return dp[n];
    }
}; 

14) Fibbonaci Series

TC->O(N)
SC->O(1)

class Solution {
public:
    int fib(int n) {
        int dp[2];
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
            dp[i%2]=dp[0]+dp[1];
        return dp[n%2];
    }
};

15) Two Sum II - Input array is sorted

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

16) Majority Element 

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

17) Pascal's Triangle
//Display Triangle

TC -> O(N^2)
SC -> O(N^2)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> pascal;
        for(int i=1;i<=numRows;i++)
        {
            vector<int> row(i);
            row[0]=1;
            row[i-1]=1;
            for(int j=1;j<i-1;j++)
            { //if(row[j]!=1)
              row[j]=pascal[i-2][j]+pascal[i-2][j-1];   
            }    
            pascal.push_back(row);
        }
        return pascal;
    }
};

18) Pascal's Triangle 2 
//Display Row

TC -> O(N^2)
SC -> O(N)

class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<int> result;
        if(rowIndex<0)
            return result;
        result.push_back(1);
        for(int i=1;i<=rowIndex;i++)
        {
            result.resize(i+1);
            result[0]=result[i]=1;
            for(int j=i-1;j>0;j--)
            {
                result[j]=result[j]+result[j-1];
            }
        }
        return result;
    }
};