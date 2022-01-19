1588. Sum of All Odd Length Subarrays

/* Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.

A subarray is a contiguous subsequence of the array. 

Return the sum of all odd-length subarrays of arr. */

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

