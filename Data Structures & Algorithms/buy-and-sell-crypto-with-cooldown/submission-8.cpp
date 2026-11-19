class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();

        vector<vector<int>> dp(n+1, vector<int> (3, -1));

        return bt(prices, 0, 0, n, dp);
    }

    int bt(vector<int>& prices, int i, int state, int n, vector<vector<int>>& dp){
        if (i == n) return 0;

        // state:
        // 0 - neutral
        // 1 - buy
        // 2 - cooldown
        if(state == 2) {
            if(dp[i][2] != -1) return dp[i][2];
            return dp[i][2] = bt(prices, i+1, 0,  n, dp);
        }
        if(state == 1) {
            if(dp[i][1] != -1) return dp[i][1];
            return dp[i][1] = max(bt(prices, i+1, 2, n, dp) + prices[i], bt(prices, i+1, 1, n, dp));
            }
        else {
            if(dp[i][0] != -1) return dp[i][0];
            return dp[i][0] = max(bt(prices, i+1, 0, n, dp), bt(prices, i+1, 1, n, dp) - prices[i]);
        }
    }
};
