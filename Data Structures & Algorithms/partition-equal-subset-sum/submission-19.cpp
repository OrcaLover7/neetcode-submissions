class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        vector<vector<int>> dp(n+1, vector<int>(sum/2 + 1, -1));
        return bt(nums, 0, sum/2, dp);
    }

    bool bt(vector<int>& nums, int i, int target, vector<vector<int>>& dp){
        if(target < 0 or i > (int)nums.size()) return false;
        if(i == (int)nums.size() and target) return dp[i][target] = false;
        if(target == 0) return dp[i][target] = true;
        

        if(dp[i][target] != -1) return dp[i][target];

        return dp[i][target] = bt(nums, i+1, target, dp) or bt(nums, i+1, target - nums[i], dp);
    }
};
