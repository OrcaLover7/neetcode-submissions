class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();

        vector<vector<int>> ans = {{}};

        int start = 0;
        int prevStart = 0;

        for(int i = 0; i < n; i++){
            start = (i >= 1 && nums[i] == nums[i-1]) ? prevStart : 0;
            prevStart = ans.size();

            for(int j = start; j < prevStart; j++){
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }

        }

        return ans;
    }
};
