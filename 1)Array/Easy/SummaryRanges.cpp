9) Summary Ranges(#228)

/* You are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b */
a) TC-> O(N)
SC-> O(N)

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> results;       
        int low=0,high=0;
        if(nums.size()==1)
        {
           string s=to_string(nums[0]);
            results.push_back(s);
            return results;
        } 
        for(int i=1;i<nums.size();i++)
        {
            string range,s1,s2;
            if(nums[i-1]+1==nums[i])
            {   high=i;                
            }
            else{
                if(high>low){
            s1=to_string(nums[low]);
            s2=to_string(nums[high]);
            range.append(s1);
            range.append("->");
            range.append(s2);
            results.push_back(range);
            low=i;
            high=i;
            }
            else if(nums[low]==nums[high])
            {   string s=to_string(nums[low]); 
                results.push_back(s);
             low=i;
            high=i;
            }
            }
           // range.clear();
        }        
        if(high==nums.size()-1)
        {
            if(high>low){
            string s1=to_string(nums[low]);
            string s2=to_string(nums[high]);
            string range;
            range.append(s1);
            range.append("->");
            range.append(s2);
            results.push_back(range);            
            }
            else if(nums[low]==nums[high])
            {   string s=to_string(nums[low]); 
                results.push_back(s);
            } 
        }
        return results;
    }
};

b) TC-> O(N)
SC-> O(N)

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> f1;
        for(int i = 0;i<nums.size();){
            string f = "";
            f +=(to_string(nums[i]));
            int flag = 0;
            while(i+1<nums.size() && nums[i+1]==nums[i]+1){
                flag = 1;
                i++;
            }
            if(flag){
                f+="->" + to_string(nums[i]);
            }
            i++;
            f1.push_back(f);
        }
        return f1;
    }
};
