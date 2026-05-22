class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = (int)nums.size();

        vector<bool> v(n, false);
        vector<int> perm;

        bt(nums, v, perm, ans);

        return ans;
    }

    void bt(vector<int>& nums, vector<bool>& v, vector<int>& perm, vector<vector<int>>& ans){
        if(perm.size() == nums.size()){
            ans.push_back(perm);
            return;
        }

        for(int i = 0; i < (int)nums.size(); i++){
            if(!v[i]){
                perm.push_back(nums[i]);
                v[i] = true;
                bt(nums, v, perm, ans);
                v[i] = false;
                perm.pop_back();
            }
        }
    }
};
