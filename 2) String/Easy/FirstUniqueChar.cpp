3) 387. First Unique Character in a String
/* Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.*/

TC->O(N^2)
SC->O(1)

class Solution {
public:
    int firstUniqChar(string s) {
        for(char i:s)
          if(s.find_first_of(i)==s.find_last_of(i)) return s.find_first_of(i);
        return -1;
    }
};