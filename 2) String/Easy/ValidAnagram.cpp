5) 242. Valid Anagram
/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.*/

TC->O(3N)
Sc->O(N)

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m(26);
        for(char i:s)
            ++m[i];
        for(char i:t)
            if(--m[i]<0)
                return false;
        for(auto i:m)
            if(i.second!=0)
                return false;
        return true;
    }
};