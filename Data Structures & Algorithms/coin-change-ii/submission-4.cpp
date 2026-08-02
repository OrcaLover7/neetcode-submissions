class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);

        dp[0] = 1;

        for(int coin : coins){
            for(int i = 1; i <= amount; i++){
                int prev = i - coin;
                if(prev >= 0) dp[i] += dp[prev]; 
            }
        }

        return dp[amount];
    }
};
