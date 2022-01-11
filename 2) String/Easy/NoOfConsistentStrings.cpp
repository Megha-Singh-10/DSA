2) 1684. Count the Number of Consistent Strings

/* You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.*/

TC->O(N^2)
SC->O(1)

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int i,count=0,flag=0;
        for(string t : words)
        {
            flag=0;
           for(i=0;i<t.size();i++)
           {
               if(allowed.find(t[i])==string::npos)
               {  flag=0;
                   break;}
               else
                   flag=1;  
           }
            if(flag==1)
                count++;
        }
        return count;
    }
};