class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        bt(nums, curr, 0, ans);

        return ans;
    }

    void bt(vector<int>& nums, vector<int>& curr, int i, vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        bt(nums, curr, i+1, ans);
        curr.pop_back();
        bt(nums, curr, i+1, ans);
    }
};
