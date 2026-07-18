class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();

        vector<vector<int>> dp(n, vector<int> (3, 0));
        //j = 0 -> hold on day i
        //j = 1 -> sell on day i
        //j = 2 -> rest on day i
        int hold = -prices[0];
        int sold = 0, rest = 0;
        // dp[0][0] = -prices[0];
        // dp[0][1] = 0;
        // dp[0][2] = 0;

        for(int i = 1; i < n; i++){
            int new_hold = max(hold, rest - prices[i]);
            int new_sold = hold + prices[i];
            int new_rest = max(rest, sold);

            hold = new_hold;
            sold = new_sold;
            rest = new_rest;
            // dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]);
            // dp[i][1] = dp[i-1][0] + prices[i];
            // dp[i][2] = max(dp[i-1][2], dp[i-1][1]);
        }

        return max(sold, rest);
    }
};
