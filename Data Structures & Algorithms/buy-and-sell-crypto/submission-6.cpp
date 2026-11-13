class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int n = (int)prices.size();

        int l = 0, r = 0;

        while(r < n){
            profit = max(profit, prices[r] - prices[l]);
            if(prices[r] < prices[l]) l = r;

            r++;
        }

        return profit;
    }
};
