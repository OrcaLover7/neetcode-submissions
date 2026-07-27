class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2) return false;
        int target = sum/2;
        vector<bool> v(n, false);
        vector<int> dp(target + 1, -1);

        return bt(nums, target, v, n, dp);

    }

    bool bt(vector<int>& nums, int target, vector<bool>& v, int n, vector<int>& dp){
        if(target == 0) return true;
        if(target < 0) return false;

        if(dp[target] != -1) return dp[target];

        for(int i = 0; i < n; i++){
            if(!v[i]){
                v[i] = true;
                if(bt(nums, target - nums[i], v, n, dp)) return dp[target] = true;;
                v[i] = false;
            }
        }

        return dp[target] = false;
    }
};
