class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();

        vector<vector<int>> dp(n+1, vector<int> (3, -1));

        return bt(prices, 0, false, false, n, dp);
    }

    int bt(vector<int>& prices, int i, bool cd, bool bought, int n, vector<vector<int>>& dp){
        if (i == n) return 0;

        if(cd) {
            if(dp[i][0] != -1) return dp[i][0];
            return dp[i][0] = bt(prices, i+1, false, false, n, dp);
        }
        if(bought) {
            if(dp[i][1] != -1) return dp[i][1];
            return dp[i][1] = max(bt(prices, i+1, true, false, n, dp) + prices[i], bt(prices, i+1, false, true, n, dp));
            }
        else {
            if(dp[i][2] != -1) return dp[i][2];
            return dp[i][2] = max(bt(prices, i+1, false, false, n, dp), bt(prices, i+1, false, true, n, dp) - prices[i]);
        }
    }
};
