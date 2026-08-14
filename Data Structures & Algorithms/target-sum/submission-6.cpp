class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int S = accumulate(nums.begin(), nums.end(), 0);

        if(target > S or target < -S) return 0;

        vector<unordered_map<int, int>> dp(n+1);
        dp[0][0] = 1;

        for(int i = 0; i < n; i++){
            for(auto& [k, v] : dp[i]){
                dp[i+1][k + nums[i]] += v;
                dp[i+1][k - nums[i]] += v;
            }
        }

        return dp[n][target];
    }
};
