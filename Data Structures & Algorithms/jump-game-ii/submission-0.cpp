class Solution {
public:
    int jump(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> dp(n, INT_MAX);

        dp[0] = 0;

        for(int i = 0; i < n; i++){
            int k = nums[i];

            for(int j = i+1; j < n && k; j++, k--){
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }

        return dp[n-1];
    }
};
