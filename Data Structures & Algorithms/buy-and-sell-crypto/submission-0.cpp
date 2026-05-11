class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();

        int l = 0, r = 0, profit = 0;

        while(r < n){
            int curr = prices[r];

            if(curr < prices[l])
                l = r;
            profit = max(profit, curr-prices[l]);
            r++;
        }

        return profit;
    }
};
