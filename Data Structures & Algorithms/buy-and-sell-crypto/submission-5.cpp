class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int n = (int)prices.size();

        for(int i = 0; i < n; i++){
            int p0 = prices[i];

            for(int j = i+1; j < n; j++) profit = max(profit, prices[j] - p0);
        }

        return profit;
    }
};
