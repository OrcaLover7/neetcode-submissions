class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = (int)nums.size();

        vector<int> dp1(n, INT_MIN), dp2(n, INT_MAX);

        dp1[0] = nums[0];
        dp2[0] = nums[0];
        int ans = nums[0];

        for(int i = 1; i < n; i++){
            dp2[i] = min(min(dp2[i-1]*nums[i], dp1[i-1]*nums[i]), nums[i]);
            dp1[i] = max(max(dp1[i-1]*nums[i], dp2[i-1]*nums[i]), nums[i]);

            ans = max(ans, dp1[i]);
        }

        return ans;
    }
};
