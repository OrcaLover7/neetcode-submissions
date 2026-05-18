class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        bt(nums, 0, curr, ans);
        return ans;
    }

    void bt(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(subset);
            return;
        }

        bt(nums, i+1, subset, ans);

        subset.push_back(nums[i]);
        bt(nums, i+1, subset, ans);
        subset.pop_back();
    }
};
