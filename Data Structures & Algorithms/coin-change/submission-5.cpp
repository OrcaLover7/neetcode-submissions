class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = (int)coins.size();
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        sort(coins.begin(), coins.end());

        for(int i = 0; i <= amount; i++){  
            for(int coin : coins){
                int diff = i - coin;
                if(diff >= 0){
                    dp[i] = min(dp[i], dp[diff] + 1);
                }
                else break;
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
