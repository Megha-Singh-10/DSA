1281. Subtract the Product and Sum of Digits of an Integer
/* Given an integer number n, return the difference between the product of its digits and the sum of its digits. */

TC-> O(N) //n= no of digits of the number
SC->O(1)

class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod=1,sum=0,digit;
        while(n!=0)
        {
            digit=n%10;
            prod*=digit;
            sum+=digit;
            n/=10;
        }
        return prod-sum;
    }
};