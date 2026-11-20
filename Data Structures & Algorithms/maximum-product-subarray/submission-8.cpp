class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = (int)nums.size();

        int max_sf, min_sf, max_eh, min_eh;
        max_sf = min_sf = max_eh = min_eh = nums[0];

        for(int i = 1; i < n; i++){
            int temp_min_eh = min_eh;
            min_eh = min({max_eh*nums[i], min_eh*nums[i], nums[i]});
            max_eh = max({max_eh*nums[i], temp_min_eh*nums[i], nums[i]});
            max_sf = max(max_sf, max_eh);
        }

        return max_sf;
    }
};
