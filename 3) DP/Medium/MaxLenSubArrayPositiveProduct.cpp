2) Maximum Length of Subarray With Positive Product(#1567)

/* Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.*/

TC->O(3N)
SC-> O(1)

class Solution {
public:
    
    int getMaxLenHelper(vector<int> &a,int s,int e)
    {
        if(s==e)                 // Base case       
            return 0;
        int f = -1 ;
        for(int i=s;i<e;i++)    // Finding first zero element index in array
        {
            if(a[i]==0)
            {
                f = i;
                break;
            }
        }
        if(f!=-1)    // If zero found call same function on left and right hand side of zero
        {
            int h = getMaxLenHelper(a,s,f);       
            int k = getMaxLenHelper(a,f+1,e);
            return max(h,k);
        }
        f=0;
        for(int i=s;i<e;i++)    // Counting number of negitive element in array
            if(a[i]<0)
                f++;
        if(f%2==0)        // Even negtive multiplication is always positive
            return (e-s);
        int h , k ;
        for(int i=s;i<e;i++)     // Finding first occurrence of negitive element
        {
            if(a[i]<0)
            {
                h = i;
                break;
            }
        }
        for(int i=e-1;i>=s;i--)    // Finding last occurrence of negative element
        {
            if(a[i]<0)
            {
                k=i;
                break;
            }
        }
        
        return max(e-h-1,k-s);   // Return accordingly 
        
        
    }
    
    
    int getMaxLen(vector<int>& a) {
        
        int s =0 ;             // Strating of array
        int e  = a.size();     // Ending of array
        return getMaxLenHelper(a,s,e);   // Helper function for devide array with respect to element zero
    }
};