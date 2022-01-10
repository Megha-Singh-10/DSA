

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

19) Valid Palindrome (String)

TC-> O(N)
SC->O(1)

class Solution {
public:
    bool isPalindrome(string s) {
       //int half=s.length()/2;
        int i=0;
        int j=s.length()-1;
       // s=tolower(s);
       for_each(s.begin(), s.end(), [](char & c){
    c = toupper(c);
});
       while(i<=j)
       {
           if(!isalnum(s[i])){ 
               i++;
               continue;
           }
           if(!isalnum(s[j])) {
               j--;
               continue;
           }   
               if(s[i]!=s[j]) //if (toupper(s[i]) != toupper(s[j]))
                   return false;          
           i++;
           j--;
       }
        return true;
    }
};

20) Convert 1D Array Into 2D Array

a) TC-> O(N^2)
SC-> O(N^2)

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> newArray(m,vector<int>(n));
        vector<vector<int>> no; //to return empty array
        if(original.size()!=m*n)
            return no;
        int k=0;
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               newArray[i][j]=original[k++];
           }
       }
        return newArray;
    }
};

b) TC-> O(N)
SC-> O(N^2)

for(int i=0;i<original.length;i++)
		result[i/n][i%n] = original[i];

21) Maximum Subarray (Kadane's Algorithm)
TC-> O(N)
SC-> O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxi=INT_MIN;
        for(int i: nums)
        {
            sum+=i;
            maxi=max(sum,maxi);
            if(sum<0) sum=0;
        }
        return maxi;
    }
};

22) Contains Duplicate II (Based on condition)
TC-> O(N)
SC-> O(N)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end()) m[nums[i]]=i;
            else
            {
                if(abs(m[nums[i]]-i)<=k) return true;
                m[nums[i]]=i;
            }
        }
        return false;
    }
};

23) Merge Sorted array

TC->O(N)
SC->O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m-1,p2=n-1,i=m+n-1;
        while(p2>=0)
        {
            if(p1>=0 && nums1[p1]>nums2[p2])
                nums1[i--]=nums1[p1--];
            else
                nums1[i--]=nums2[p2--];
        }
    }
};

24) Intersection of two array

a) TC-> O(N)
SC-> O(N)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> result;
        int small,big;
        if(nums1.size()<nums2.size()) 
        {
            big=nums2.size();
            small=nums1.size();
        for(int i=0;i<small;i++)
        {
            if(m.find(nums1[i])==m.end())
            {
                m[nums1[i]]=0;                
            }
        }
            
         for(int i=0;i<big;i++)
         {
             if(m.find(nums2[i])!=m.end())
             {
                 m[nums2[i]]=1;
             }  
         }          
        }
        else
        {
             big=nums1.size();
            small=nums2.size();
        for(int i=0;i<small;i++)
        {
            if(m.find(nums2[i])==m.end())
            {
                m[nums2[i]]=0;
            }
        }
         for(int i=0;i<big;i++)
         {
             if(m.find(nums1[i])!=m.end())
             {
                 m[nums1[i]]=1;                
             }
         }
          
        }     
        
       // for(auto j=m.begin();j!=m.end();++j)
        for(auto i:m)
          {
              if(i.second>0)
                  result.push_back(i.first);   //j->first       
            //cout<<i.first<<" "<<i.second<<"\n";
          }                
        return result;
    }
};

b) TC-> O(N*N)
   SC-> O(N)

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s(nums1.begin(), nums1.end());
    vector<int> out;
    for (int x : nums2)
        if (s.erase(x)) //erase TC->O(N)
            out.push_back(x);
    return out;
}

25) Intersection of two arrays 2

a) TC-> O(N*M) //M-> no of times one element is repeated
SC->O(N)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {       
        vector<int> result;
        //if(nums1.size()>nums2.size()) result=intersect(nums2,nums1);
        unordered_map<int,pair<int,int>> m;
        for(int i:nums1)
        {
            if(m.find(i)==m.end())
            {
                m[i].first=1;
                m[i].second=0;
            }
            else
                m[i].first++;
        }
        for(int i:nums2)
        {
            if(m.find(i)!=m.end())
            {
                m[i].second++;
            }
        }
        for(auto i:m)
        {//cout<<"\n "<<i.first<<" "<<i.second.first<<" "<<i.second.second;
            int n=i.second.first<=i.second.second? i.second.first : i.second.second;
            while(n)
            {
              result.push_back(i.first);
              n--;
            }
        }
        return result;
    }
};

b) TC-> O(N+M) //N is size of num1 and M is size of num2
   SC-> O(N+M)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
        for(int i = 0; i < (int)nums2.size(); i++)
            if(--dict[nums2[i]] >= 0) res.push_back(nums2[i]);
        return res;
    }
};   

26) Reshape the matrix
TC-> O(N*N)
SC-> O(N*N)

a) class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
       // if(mat[0].size()==r && mat.size()==c)
       //     return mat;
        int m=mat.size();
        int n=mat[0].size();
        if(n*m!=r*c)
            return mat;
       vector<vector<int>> result(r,vector<int>(c));
        int row=0,col=0;       
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {               
                result[row][col]=mat[i][j];
                // col=(col+1)%n;
                // if(col==0)
                //     row++;
                if(col<c-1) col++;
                else if(col==c-1)
                {
                    col=0;
                    row++;
                }
            }            
        }
        return result;
    }
};

b) class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
       //if(mat.size()==r && mat[0].size()==c)
         //   return mat;
        int m=mat.size();
        int n=mat[0].size();
        if(n*m!=r*c)
            return mat;
       vector<vector<int>> result(r,vector<int>(c));
        int row=0,col=0;       
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {               
                //result[row][col]=mat[i][j];
                result[i][j]=mat[row][col];
                col=(col+1)%n;
                if(col==0)
                    row++;                
            }            
        }
        return result;
    }
};

c) matrix traversal in one loop-> matrix[index / width][index % width]

TC-> O(r*c)
SC-> O(r*c)

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if(n*m != r*c)return mat;
        vector<vector<int>>v(r, vector<int>(c,0));
        for(int i = 0; i<r*c; i++)        
            v[i/c][i%c] = mat[i/n][i%n];
        return v;
    }

27) Palindrome
