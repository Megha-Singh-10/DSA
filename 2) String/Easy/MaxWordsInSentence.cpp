2114. Maximum Number of Words Found in Sentences
/* A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

You are given an array of strings sentences, where each sentences[i] represents a single sentence.

Return the maximum number of words that appear in a single sentence.*/

a) TC->O(N^2)
SC->O(1)

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxC=INT_MIN,count=0;
        for(auto i: sentences)
        {
            count=0;
            for(int j=0;j<i.size();j++)
            {
                if(i[j]==' ')
                {
                    count++;                  
                }   
            }
            count++;
            maxC=max(maxC,count);
        }
        return maxC;
    }
};

b) int mostWordsFound(vector<string>& s) {
    return 1 + accumulate(begin(s), end(s), 0, [](int res, const auto &s) {
        return max(res, (int)count(begin(s), end(s), ' ')); });
}