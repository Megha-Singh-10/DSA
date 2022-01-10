25) Intersection of two arrays 2(#350)

/* Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order. */

a) TC-> O(N*M) //M-> no of times one element is repeated
SC->O(N)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {       
        vector<int> result;
        //if(nums1.size()>nums2.size()) result=intersect(nums2,nums1);
        unordered_map<int,pair<int,int>> m;
        for(int i:nums1)
        {
            if(m.find(i)==m.end())
            {
                m[i].first=1;
                m[i].second=0;
            }
            else
                m[i].first++;
        }
        for(int i:nums2)
        {
            if(m.find(i)!=m.end())
            {
                m[i].second++;
            }
        }
        for(auto i:m)
        {//cout<<"\n "<<i.first<<" "<<i.second.first<<" "<<i.second.second;
            int n=i.second.first<=i.second.second? i.second.first : i.second.second;
            while(n)
            {
              result.push_back(i.first);
              n--;
            }
        }
        return result;
    }
};

b) TC-> O(N+M) //N is size of num1 and M is size of num2
   SC-> O(N+M)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
        for(int i = 0; i < (int)nums2.size(); i++)
            if(--dict[nums2[i]] >= 0) res.push_back(nums2[i]);
        return res;
    }
};   