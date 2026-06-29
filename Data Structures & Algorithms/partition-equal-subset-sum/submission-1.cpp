class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size();
        int total = 0;

        for(int i : nums) total += i;

        if(total%2) return false;
        vector<int> v(n, 0);
        vector<int> dp(total/2+1, -1);

        return bt(nums, total/2, v, n, dp);
    }

    bool bt(vector<int>& nums, int target, vector<int>& v, int n, vector<int>& dp){
        if(target == 0) return true;
        if(target < 0) return false;

        if(dp[target] != -1) return dp[target];

        for(int i = 0; i < n; i++){
            if(!v[i]){
                v[i] = 1;
                if(bt(nums, target-nums[i], v, n, dp)) return dp[target] = true;
                v[i] = 0;
            }
        }

        return dp[target] = false;
    }
};
