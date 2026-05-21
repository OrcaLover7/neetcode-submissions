class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 1) return nums[0];

        return max(rob_linear(nums, 0, n-2), rob_linear(nums, 1, n-1));
    }

    int rob_linear(vector<int>& nums, int l, int r){
        int n = r-l+1;
        if(n == 1) return nums[l];
        int a = nums[l];
        int b = max(nums[l], nums[l+1]);

        for(int i = l+2; i <= r; i++){
            int c = max(b, nums[i] + a);
            a = b;
            b = c;
        }

        return b;
    }
};
