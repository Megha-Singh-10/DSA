728. Self Dividing Numbers
/* A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
A self-dividing number is not allowed to contain the digit zero.

Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right]. */

TC->O(N^2)
SC->O(N)

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        int num,rem,n;
        for(int i=left;i<=right;i++)
        {
            num=i;
            n=i;
            while(n!=0)
            {
                rem=n%10;
                if(rem==0 || num%rem!=0)
                    break;                                   
                n/=10;
            }
            if(n==0)
                 result.push_back(num);
        }
        return result;
    }
};