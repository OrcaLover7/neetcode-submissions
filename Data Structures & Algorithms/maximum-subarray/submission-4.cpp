class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0];
        int ans = nums[0];

        for(int i = 1; i < n; i++){
            a = max(a + nums[i], nums[i]);
            ans = max(ans, a);
        }

        return ans;
    }
};
