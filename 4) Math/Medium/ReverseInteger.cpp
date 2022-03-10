7. Reverse Integer
/* Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.*/

a) TC-> O(N)
SC-> O(1)

class Solution {
public:
    int reverse(int x) {
        int result=0;
        while(x!=0)
        {
            int rem=x%10;
            //-2147483648 = -2^31 = INT_MIN 
            /* result*10+rem<INT_MIN --> overflows
            => result*10<INT_MIN-rem  --->overflows
            =>result<(INT_MIN-rem)/10  ---> does not overflow
            hence this eqn can be used to checck overflow condition
            */
           // if(result*10+rem<INT_MIN || result*10+rem>INT_MAX)
            if((result>0 && result>(INT_MAX-rem)/10)||(result<0 && result<(INT_MIN-rem)/10))
                return 0;
            result=result*10+rem;
            x=x/10;
        }        
            return result;
    }
};

b) TC->O(N)
SC-> O(1)

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : (int)res;
    }
};
