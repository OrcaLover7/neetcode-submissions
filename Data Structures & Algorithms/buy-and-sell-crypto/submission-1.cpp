class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int l = 0, r = 0, profit = 0;

        while(r < (int)prices.size()){
            if(prices[r] < prices[l])
                l = r;
            profit = max(profit, prices[r]-prices[l]);
            r++;
        }

        return profit;
    }
};
