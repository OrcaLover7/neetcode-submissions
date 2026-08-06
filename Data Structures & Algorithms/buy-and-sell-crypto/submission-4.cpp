class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int l = 0, r = 0, profit = 0;

        while(r < (int)prices.size()){
            profit = max(profit, prices[r]-prices[l]);
            if(prices[r] < prices[l])
                l = r;
            r++;
        }

        return profit;
    }
};
