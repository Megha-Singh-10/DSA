1588. Sum of All Odd Length Subarrays

/* Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.

A subarray is a contiguous subsequence of the array. 

Return the sum of all odd-length subarrays of arr. */

TC-> O(N^3)
  SC->O(1)

a)

  class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
       int n=arr.size();
       int res=0;
        if(n==0) return 0;
        if(n==1) return arr[0];
        if(n==2) return arr[0]+arr[1];
       // cout<<"res "<<res<<endl;
        
        for(int i:arr)
            res+=i;
        for(int j=3;j<=n;j+=2)
        { 
            // cout<<" j "<<j<<endl;
            for(int i=0;i<=n-j;i++) 
            {
                // cout<<"   i "<<i<<endl;
                int k=i;
             int count=0;
                while(count<j)  //to add element from i to k
                {  
                    // cout<<"    k "<<k;
                    res+=arr[k++];
                 count++;
                 // cout<<" res "<<res<<endl;               
                }
            }
        }
        return res;
    }
};

b)

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int totalSum=0;
        
        for(int i=0; i<arr.size(); i++) {
            for(int j=i; j<arr.size(); j+=2) {
                for(int k=i; k<=j; k++) {
                    totalSum+=arr[k];
                }
            }
        }
        return totalSum;
    }
};

c) TC->O(N)
   SC-> O(1)

   /*Just see number of times every position occurs in all the odd length subarray.
Multiply the contribution of position with element at that position.

How to calculate contribution?
Every element will contribute size of array to its right (n-i) * size of array to its left(i+1)
Since here we only consider odd length divide it by two (ceil divison)


Example 
Given array: arr = [1, 2, 3, 4, 5] (n = 5) and formula (i + 1) * (n - i)
i = 0, contribution = 1 * 5 = 5
i = 1, contribution = 2 * 4 = 8
i = 2, contribution = 3 * 3 = 9
i = 3, contribution = 4 * 2 = 8
i = 4, contribution = 5 * 1 = 5*/

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
       int res=0,n=arr.size(),contribution;
        for(int i=0;i<n;i++)
        {
            contribution=ceil(((i+1)*(n-i))/2.0);
            res+=(contribution*arr[i]);
        }
        return res;
    }
};