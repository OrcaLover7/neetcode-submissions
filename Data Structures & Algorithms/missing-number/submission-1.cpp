class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;

        for(int i = 0; i < (int)nums.size(); i++) ans ^= nums[i]^(i+1);

        return ans;
    }
};
