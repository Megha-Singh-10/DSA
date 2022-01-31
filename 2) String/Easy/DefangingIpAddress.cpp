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