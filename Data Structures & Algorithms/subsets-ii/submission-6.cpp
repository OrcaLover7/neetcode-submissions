class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        bt(nums, 0, sub, ans);

        return ans;
    }

    void bt(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& ans){
        ans.push_back(sub);

        for(int i = start; i < (int)nums.size(); i++){
            if(i > start && nums[i] == nums[i-1]) continue;
            sub.push_back(nums[i]);
            bt(nums, i+1, sub, ans);
            sub.pop_back();
        }
    }
};
