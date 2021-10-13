1) Buy and Sell Stock 2 //Buy sell again buy sell ---n times to get max profit

a) TC->O(N)
   SC->O(1)

   class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0,minPrice=INT_MAX,totalProfit=0;
        for(int i=0;i<prices.size();i++)
        {
            minPrice=min(minPrice,prices[i]);
            maxProfit=max(maxProfit,prices[i]-minPrice);
            if(maxProfit>0 && prices[i]<prices[i-1])
            {
                totalProfit+=maxProfit;
                minPrice=prices[i];
                maxProfit=0;
            }
        }
        totalProfit+=maxProfit;
        return totalProfit;
    }
};

b) TC->O(N)
   SC->O(1)

   class Solution{
       public:
       int maxProfit(vector<int>& prices)
       {
           int totalProfit=0;
           for(int i=1;i<prices.size();i++)           
               totalProfit+=max(prices[i]-prices[i-1],0);
           return totalProfit;           
       }
   };

2) Rotate Image

TC-> O(N^2)
SC->O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& a) { //Part-1 & Part-2 order can be vice versa
        int first,last,row,col;
        int n=a[0].size();
        int m=a.size();
        for(int i=0;i<n;i++) //part-1
        {
            for(int j=0;j<i;j++)
            {                              
                int temp;
                temp=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=temp;
            }
        }
        int half=abs(m/2);
        for(int j=0;j<half;j++) //part-2
        {
             first=j;
             last=n-j-1;                    
           for(int i=0;i<n;i++)
            {
            int temp=a[i][first];
            a[i][first]=a[i][last];
            a[i][last]=temp;
            }                     
        }             
    }
};

3) Decode Ways

TC->O(N)
SC->O(1)

class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==0)
            return 0;
        if(s[0]=='0')
            return 0;
        if(s.length()==1)
            return 1;   
        int val1=1,val2=1;
        for(int i=1;i<s.length();i++)
        {
            int d=s[i]-'0';
            int dd=(s[i-1]-'0')*10+d;
            int val=0;
            if(d>=1)
                val+=val2;
            if(dd>=10 && dd<=26)
                val+=val1;
            val1=val2;
            val2=val;
        }
        return val2;
    }
};

4) Subrectangle Queries

TC -> O(N^2)
SC -> O(N^2)

class SubrectangleQueries {
public:
    vector<vector<int>> rect;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect=rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i=row1;i<=row2;i++)
        {
            for(int j=col1;j<=col2;j++)
            {
                rect[i][j]=newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return rect[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */

5) Next Permutation

TC-> O(3N)
SC-> O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j;
        for(i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
                break;
        }
        if(i<0)
            reverse(nums.begin(),nums.end());
        else
        {
            for(j=nums.size()-1;j>=i;j--)
            {
                if(nums[i]<nums[j])
                    break;
            }
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
        }        
    }
};

