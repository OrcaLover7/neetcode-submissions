class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        bt(nums, 0, ans);

        return ans;
    }

    void bt(vector<int>& nums, int start, vector<vector<int>>& ans){
        if(start== nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = start; i < (int)nums.size(); i++){
            swap(nums[start], nums[i]);
            bt(nums, start+ 1, ans);
            swap(nums[start], nums[i]);
        }
    }
};
