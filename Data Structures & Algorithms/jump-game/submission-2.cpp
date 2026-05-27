class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = (int)nums.size();

        vector<int> dp(n, 0);

        dp[0] = 1;

        for(int i = 0; i < n; i++){
            if(dp[i]){
                int k = nums[i];
                int j = i+1;
                while(j < n && k--){
                    dp[j] = 1;
                    j++;
                }
            }
            if(dp[n-1]) return true;
        }

        return false;
    }
};
