1) Remove all occurrences of a substring (#1910)

/* Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.*/

TC-> O(2N*M) //O(N) for find() O(N) for erase() M is number of substrings
SC-> O(1)

class Solution {
public:
    string removeOccurrences(string s, string part) {
        auto found= s.find(part); // size_t found = s.find(part); 
        while(found!=string::npos)
        {
            s.erase(s.begin()+found,s.begin()+found+part.length());
            found=s.find(part);
        }
        return s;    
    }
    
};