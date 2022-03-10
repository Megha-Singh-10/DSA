69. Sqrt(x)
/* Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned. */

TC->O(logN)
SC->O(1)

class Solution {
public:
    int mySqrt(int x) {
        long start=0,end=x,mid;
        while(start+1<end)
        {
            mid=(start+end)/2;
            if(mid*mid==x)
                return mid;
            else if(mid*mid<x)
                start=mid;
            else
                end=mid;
        }
        if(end*end==x)
            return end;
        return start;
    }
};