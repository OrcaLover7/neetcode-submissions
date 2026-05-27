class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> sub;
        vector<vector<int>> ans;

        bt(nums, 0, sub, ans);

        return ans;
    }

    void bt(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& ans){
        if(start == (int)nums.size()){
            ans.push_back(sub);
            return;
        }

        sub.push_back(nums[start]);
        bt(nums, start+1, sub, ans);
        sub.pop_back();

        while(start + 1 < (int)nums.size() && nums[start] == nums[start+1]) start++;

        bt(nums, start+1, sub, ans);
    }
};
