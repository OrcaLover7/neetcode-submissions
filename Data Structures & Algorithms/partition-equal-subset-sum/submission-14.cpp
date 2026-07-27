class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2) return false;
        int target = sum/2;
        
        //dp[i] = true if i is reachable
        //dp[i] |= dp[i - num] for all valid numbers.

        vector<int> dp(target + 1, 0);

        dp[0] = 1;

        for(int num : nums){
            for(int k = target; k >= num; k--) dp[k] |= dp[k-num];
            if(dp[target]) return true;
        }

        return dp[target];

    }

};
