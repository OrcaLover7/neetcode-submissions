class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if(total%2) return false;

        int target = total/2;
        vector<int> dp(target+1, 0);

        dp[0] = 1;

        for(int num : nums){
            for(int k = target; k >= num; k--) dp[k] |= dp[k-num];
            if(dp[target]) return true;
        }

        return dp[target];
    }
};
