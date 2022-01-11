4) 383. Ransom Note
/*Given two stings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.*/

TC->O(2N)
SC->O(N)

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m(26);
        for(char i:magazine)
            ++m[i];
        for(char i:ransomNote)
            if(--m[i]<0) return false;
        return true;
    }
};