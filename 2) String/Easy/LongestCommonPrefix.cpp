7) 14. Longest Common Prefix
/* Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".*/

TC->O(N^2)
SC->O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // int len=0,j=0,minLen=INT_MAX;
        // if(strs.size()==1)
        //     return strs[0];
        // for(int i=1;i<strs.size();i++)
        // {
        //    j=0;
        //    len=0;
        //    while(j<strs[0].size() && j<strs[i].size() && strs[0][j]==strs[i][j])
        //    {
        //        len++;
        //        j++;
        //    }
        //     minLen=min(minLen,len);
        // }
        // if(minLen==0)
        //     return "";
        // else
        // {
        //     string result;
        //     int i=0;
        //     //string s=strs[0];
        //     while(minLen!=0)
        //     {
        //         result.push_back(strs[0][i]);
        //         i++;
        //         minLen--;
        //     }
        //     return result;
        // }
        
        string result=strs[0];
        for(int i=1;i<strs.size();i++)
        {
            string s=strs[i];
            int len=0;
            while(s[len]==result[len] && len<s.size() && len<result.size())
                len++;
            result=result.substr(0,len); // result=s.substr(0,len);
        }
        return result;
    }
};