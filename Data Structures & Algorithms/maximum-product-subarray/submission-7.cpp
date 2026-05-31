class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = (int)nums.size();

        int mn = 1, mx = 1;
        int ans = nums[0];

        for(int i = 0; i < n; i++){
            int temp_min = mn;
            mn = min(min(mn*nums[i], mx*nums[i]), nums[i]);
            mx = max(max(temp_min*nums[i], mx*nums[i]), nums[i]);

            ans = max(ans, mx);
        }

        return ans;
    }
};
