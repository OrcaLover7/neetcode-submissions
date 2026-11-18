class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2) return false;
        int target = sum/2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for(int i = 0; i < n; i++){
            for(int j = target; j >= nums[i]; j--){
                dp[j] = dp[j] or dp[j-nums[i]];
            }

            if(dp[target]) return true;
        }

        return dp[target];
     
    }
};
