class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> dp(n, 0);

        dp[0] = 1;
        int ans = 1;

        for(int i = 1; i < n; i++){
            int count = -1;

            for(int j = 0; j < i; j++) if(nums[j] < nums[i]) count = max(count, dp[j]);

            dp[i] = max(count+ 1, 1);

            ans = max(dp[i], ans);
        }

        return ans;
    }
};
