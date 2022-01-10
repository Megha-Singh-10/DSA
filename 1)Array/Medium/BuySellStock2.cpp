1) Buy and Sell Stock 2 (#122)//Buy sell again buy sell ---n times to get max profit

/* You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve. */

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