class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        bt(nums, -1, curr, ans);
        return ans;
    }

    void bt(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& ans){
        ans.push_back(subset);

        for(int j = i+1; j < (int)nums.size(); j++){
            subset.push_back(nums[j]);
            bt(nums, j, subset, ans);
            subset.pop_back();
        }
    }
};
