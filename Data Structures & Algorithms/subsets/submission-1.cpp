class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        bt(nums, curr, -1, ans);

        return ans;
    }

    void bt(vector<int>& nums, vector<int>& curr, int i, vector<vector<int>>& ans){
        
        ans.push_back(curr);
        for(int j = i+1; j < (int)nums.size(); j++){
            curr.push_back(nums[j]);
            bt(nums, curr, j, ans);
            curr.pop_back();
        }
    }
};
