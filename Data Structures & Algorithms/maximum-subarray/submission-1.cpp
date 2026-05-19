class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int mx = INT_MIN;
        int n = (int)nums.size();

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                ans = max(ans, sum);
            }
            
            mx = max(mx, nums[i]);
        }

        return ans == INT_MIN ? mx : ans;
    }
};
