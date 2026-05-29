class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = (int)nums.size();

        int mn_sf = nums[0];
        int mx_sf = nums[0];
        int ans = nums[0];

        for(int i = 1; i < n; i++){
            int mn_sf_new = min(min(mx_sf*nums[i], mn_sf*nums[i]), nums[i]);
            mx_sf = max(max(mx_sf*nums[i], mn_sf*nums[i]), nums[i]);
            mn_sf = mn_sf_new;

            ans = max(ans, mx_sf);
        }

        return ans;
    }
};
