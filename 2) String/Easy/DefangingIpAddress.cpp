1108. Defanging an IP Address
/* Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]". */

TC->O(N)
SC->O(N)

class Solution {
public:
    string defangIPaddr(string address) {
        string result;        
        for(char i:address)
        {
            if(i=='.')
            {   
                result+='[';
                result+='.';
               result+=']';
             }                
            else
                result+=i;
        }
        return result;
    }
};

b) class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for(auto c: address) {
            if(c=='.') {
                res+="[.]";
            } else res+=c;
        }
        return res;
    }
};

c) TC->Running a DFA-compiled regular expression against a string is indeed O(n), but can require up to O(2^m) construction time/space (where m = regular expression size).
SC->O(1)

string defangIPaddr(string address) {
  return regex_replace(address, regex("[.]"), "[.]");
}