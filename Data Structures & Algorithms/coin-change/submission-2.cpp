class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = (int)coins.size();
        sort(coins.begin(), coins.end());

        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for(int curr_amount = 1; curr_amount <= amount; curr_amount++){
            for(int coin : coins){
                int diff = curr_amount - coin;
                if(diff >= 0) dp[curr_amount] = min(dp[diff] + 1, dp[curr_amount]);
                else break;
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
