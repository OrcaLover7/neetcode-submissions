class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size();
        int total = 0;

        for(int i : nums) total += i;
        if(total%2) return false;
        int target = total/2;
        
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for(int num : nums) for(int j = target; j >= num; j--) dp[j] = dp[j] || dp[j-num];

        return dp[target];
    }

};
