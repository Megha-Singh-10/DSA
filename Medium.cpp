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