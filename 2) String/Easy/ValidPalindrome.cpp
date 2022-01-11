6) 125. Valid Palindrome
/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.*/

TC->O(2N)
SC->O(1)

class Solution {
public:
    bool isPalindrome(string s) {
       //int half=s.length()/2;
        int i=0;
        int j=s.length()-1;
       // s=tolower(s);
       for_each(s.begin(), s.end(), [](char & c){
    c = toupper(c);
});
       while(i<=j)
       {
           if(!isalnum(s[i])){ 
               i++;
               continue;
           }
           if(!isalnum(s[j])) {
               j--;
               continue;
           }   
               if(s[i]!=s[j])
                   return false;          
           i++;
           j--;
       }
        return true;
    }
};