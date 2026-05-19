class Solution {
public:
    //nubmer of ways of reaching step i = number fo ways of reaching step i-1 + step i-2
    //number of ways of reaching step 0 = 1, number of ways of reach ing step 1 = 1
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1, dp[1] = 1;

        for(int i = 2; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];

        return dp[n];
    }
};
