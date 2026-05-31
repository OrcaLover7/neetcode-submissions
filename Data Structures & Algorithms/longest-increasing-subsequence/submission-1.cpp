class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> dp;
        
        dp.push_back(nums[0]);

        int ans = 1;

        for(int i =1 ; i < n; i++){
            if(dp.back() < nums[i]){
                dp.push_back(nums[i]);
                ans++;
                continue;
            }

            int idx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            dp[idx] = nums[i];
        }

        return ans;
    }
};
