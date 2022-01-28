1979. Find Greatest Common Divisor of Array
/* Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers. */

TC-> O(2Nlog2N)
SC->O(1)

// *min_element,*max_element-> O(N)
//__gcd use Euclidean method to calculate gcd of two values. It's complexity is 𝑂(𝑙𝑜𝑔2𝑛) algorithm, where n is the upper limit of a and b.
a) class Solution {
public:
    int findGCD(vector<int>& n) {
    return __gcd(*min_element(begin(n), end(n)), *max_element(begin(n), end(n)));
}
};

b) class Solution {
    public int findGCD(int[] nums) {
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
        for(int num : nums) {
            max = Math.max(max, num);
            min = Math.min(min, num);
        }
        return gcd(min, max);
    }
    
    private int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
}

c)   TC->O(2N)
SC->O(1)

public int findGCD(int[] nums) {
        int max = 0;
        int min = 1001;
    
        // Find the min and max from array
        for(int e : nums){
            max = Math.max(max,e);
            min = Math.min(min,e);
        }
        
        // Check All divider of min (from min to 1) is also divider of max
        // If yes then return that divider otherwise return 1;
        for(int i = 1;i <= min; i++){
            int divider = min/i;
            if(min % divider == 0 && max % divider == 0) return divider;
        }
        return 1;        
    }
