class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        vector<int> sub;

        bt(nums, 0, sub, ans);

        return ans;
    }

    void bt(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& ans){
        ans.push_back(sub);

        for(int i = start; i < (int)nums.size(); i++){
            if(i > start and nums[i] == nums[i-1]) continue;
            sub.push_back(nums[i]);
            bt(nums, i+1, sub, ans);
            sub.pop_back();
        }
    }
};
