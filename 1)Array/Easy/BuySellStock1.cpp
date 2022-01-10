8) Bull And Sell Stock Best Time 1 (#121)

/* You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.  */

a) TC-> O(N^2)
   SC-> O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,j,profit,maxProfit=0;
        int n=prices.size();
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                profit=prices[j]-prices[i];
                if(profit<0)
                     profit=0;
                else
               {
                if (profit>maxProfit)                
                    maxProfit=profit;                
               }              
            }
        }
        return maxProfit;
    }
};

b) TC->O(N)
   SC->O(1)

   class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX,maxProfit=0;
        for(int i:prices)
        {
            minPrice=min(minPrice,i);
            maxProfit=max(maxProfit,i-minPrice);
        }
        return maxProfit;
    }
};
