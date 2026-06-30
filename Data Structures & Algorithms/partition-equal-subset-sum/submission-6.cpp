class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size();
        int total = 0;

        for(int i : nums) total += i;
        if(total%2) return false;
        int target = total/2;

        vector<vector<int>> dp(n+1, vector<int>(target + 1, 0));
        
        for(int i = 0; i <= n; i++) dp[i][0] = 1;


        for(int i = 1; i <= n; i++) for(int j = 1; j <= target; j++) {if(nums[i-1] <= j) dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
        else dp[i][j] = dp[i-1][j]; }

        return dp[n][target];
    }

};
