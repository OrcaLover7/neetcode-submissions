class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> sub;
        vector<vector<int>> ans;

        bt(nums, -1, sub, ans);

        return ans;
    }

    void bt(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& ans){
        ans.push_back(sub);

        for(int i = start + 1; i < (int)nums.size(); i++){
            if(i > start + 1 && nums[i] == nums[i-1]) continue;
            sub.push_back(nums[i]);
            bt(nums, i, sub, ans);
            sub.pop_back();
        }
    }
};
