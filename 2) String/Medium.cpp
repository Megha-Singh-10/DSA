1) Remove all occurrences of a substring

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