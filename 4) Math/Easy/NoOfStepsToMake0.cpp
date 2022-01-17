1342. Number of Steps to Reduce a Number to Zero

/* Given an integer num, return the number of steps to reduce it to zero.

In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

*/

a) TC->O(N)
SC->O(1)

class Solution {
public:
    int numberOfSteps(int num) {
        int count=0;
        while(num!=0)
        {   if(num%2==0) num/=2;
            else num--;
            count++;
        }
        return count;
    }
};

b) TC->O(log2(n))
   SC->O(1)

   class Solution {
public:
    int numberOfSteps(int num) {
       int ans=0;
        
        while(num) {
//             1)if num is even or num is 1; it will take 1 step to reduce
            if((num&1)==0 || num ==1) ans++;
//             if num is odd; the 2 steps; first substract 1 then divide by 2
            else ans+=2;
//             remove last bit of num
            num/=2;  // same as bitwise (num>>1)
        }
        return ans;
    }
};

c) TC->O(log(n))
SC>O(1)

if the value is divisible by 2 , it means we have to shift right most set bit by one . And when it get decrease by 1 we have to convert a set bit to 0. So ultimately what we have to do is -
Total Number of steps = (Total no. of set bits in num ) + (Size of num)

class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;int x = 0;
        for(int i=0;i<32;i++){
            if(num & (1<<i)){
                count++;
                x = i;
            }
        }
        return count+x;
    }
};