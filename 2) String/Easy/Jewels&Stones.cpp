771. Jewels and Stones
/* You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".*/

a) TC->O(NlogN) //find->logN,contains->logN
   SC->O(1)

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        for(int i=0;i<stones.length();i++)
        {
            if(jewels.find(stones[i])!=string::npos) //contains is present in c++23
                count++;
        }
        return count;
    }
};

b) TC->O(N^2) //count->O(N)
SC->O(1)
int numJewelsInStones(string jewels, string stones) { 
    int num = 0;
    for (int i = 0; i < jewels.size(); i++){
        num += count(stones.begin(), stones.end(), jewels[i]);
    }
    return num;
}


c) /*Explanation
read J and build jewels hash set.
read S and count jewels.
Complexity
I used hash set and it's O(1) time to check if it contains an element.
So the total time complexity will be O(J+S), instead of O(JS)
Space is O(J) */

 int numJewelsInStones(string J, string S) {
        int res = 0;
        unordered_set<char> setJ(J.begin(), J.end());
        for (char s : S)
            if (setJ.count(s)) res++;
        return res;
    }

    