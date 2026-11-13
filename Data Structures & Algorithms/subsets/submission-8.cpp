class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = (int)nums.size();
        vector<int> ssf;

        bt(nums, 0, ssf, ans, n);

        return ans;
    }

    void bt(vector<int>& nums, int i, vector<int>& ssf, vector<vector<int>>& ans, int n){
        if(i == n){
            ans.push_back(ssf);
            return;
        }

        bt(nums, i+1, ssf, ans, n);

        ssf.push_back(nums[i]);
        bt(nums, i+1, ssf, ans, n);
        ssf.pop_back();
    }
};
