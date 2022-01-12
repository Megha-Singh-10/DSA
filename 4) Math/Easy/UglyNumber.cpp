2) 263. Ugly Number
/* An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return true if n is an ugly number.*/

TC-> O(3N)
SC-> O(1)

class Solution {
public:
    // bool isPrime(int n)
    // {
    //     for(int i=2;i<=n/2;i++)
    //         if(n%i==0)
    //             return false;
    //     return true;
    // }
    bool isUgly(int n) {
        if(n<=0)
            return false;  
        while(n%2==0)
            n/=2;
        while(n%3==0)
            n/=3;
        while(n%5==0)
            n/=5;
        return (n==1);
        // if(n%2==0)
        //     n=n/2;
        // if(n%3==0)
        //     n=n/3;
        // if(n%5==0)
        //     n=n/5;
        // if(n==1||n==2||n==3||n==5)
        //     return true;
        // if(isPrime(n))
        //     return false;
        // for(int i=7;i<n;i++)
        // {    if((n%i==0)&&(isPrime(i)))                            
        //             return false;      
        // }
        // return true;
    }
};