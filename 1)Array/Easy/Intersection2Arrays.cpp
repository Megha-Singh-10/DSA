24) Intersection of two array (#349)

/* Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order. */

a) TC-> O(N)
SC-> O(N)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> result;
        int small,big;
        if(nums1.size()<nums2.size()) 
        {
            big=nums2.size();
            small=nums1.size();
        for(int i=0;i<small;i++)
        {
            if(m.find(nums1[i])==m.end())
            {
                m[nums1[i]]=0;                
            }
        }
            
         for(int i=0;i<big;i++)
         {
             if(m.find(nums2[i])!=m.end())
             {
                 m[nums2[i]]=1;
             }  
         }          
        }
        else
        {
             big=nums1.size();
            small=nums2.size();
        for(int i=0;i<small;i++)
        {
            if(m.find(nums2[i])==m.end())
            {
                m[nums2[i]]=0;
            }
        }
         for(int i=0;i<big;i++)
         {
             if(m.find(nums1[i])!=m.end())
             {
                 m[nums1[i]]=1;                
             }
         }
          
        }     
        
       // for(auto j=m.begin();j!=m.end();++j)
        for(auto i:m)
          {
              if(i.second>0)
                  result.push_back(i.first);   //j->first       
            //cout<<i.first<<" "<<i.second<<"\n";
          }                
        return result;
    }
};

b) TC-> O(N*N)
   SC-> O(N)

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s(nums1.begin(), nums1.end());
    vector<int> out;
    for (int x : nums2)
        if (s.erase(x)) //erase TC->O(N)
            out.push_back(x);
    return out;
}
