class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> dp(n, 0);

        dp[0] = 1;
        int ans = 1;

        for(int i = 1; i < n; i++){
            int curr_max = -1;
            for(int j = 0; j < i; j++) if(nums[j] < nums[i]) curr_max = max(curr_max, dp[j]);

            dp[i] = max(curr_max + 1, 1);

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
