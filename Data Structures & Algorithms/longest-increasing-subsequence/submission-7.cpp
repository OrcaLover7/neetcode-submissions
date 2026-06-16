class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();

        vector<int> tails;

        tails.push_back(nums[0]);

        for(int i = 1; i < n; i++){
            if(nums[i] > tails.back()) {
                tails.push_back(nums[i]);
                continue;
            }

            int idx = lower_bound(tails.begin(), tails.end(), nums[i]) - tails.begin();
            tails[idx] = nums[i];
        }

        return (int)tails.size();
    }
};
