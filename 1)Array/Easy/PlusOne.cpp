6) Plus One(No 66)

/* You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.*/

TC->O(n)
SC->O(1)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        if(digits[n]!=9)
            digits[n]+=1;
        else
        {
            for(int i=n;i>=0;i--)
            {
                if(digits[i]==9)
                    digits[i]=0;
                else
                {   digits[i]++;
                    return digits;
                }
            }
            digits[0]=1;
            digits.push_back(0);
        }
        return digits;
        
    }
};
