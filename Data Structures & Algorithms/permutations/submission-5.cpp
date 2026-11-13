class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> perm, used(n, 0);
        vector<vector<int>> perms;

        bt(nums, perm, used, perms, n);

        return perms;
    }

    void bt(vector<int>& nums, vector<int>& perm, vector<int>& used, vector<vector<int>>& perms, int n){
        if(perm.size() == nums.size()){
            perms.push_back(perm);
            return;
        }

        for(int i = 0; i < n; i++){
            if(used[i]) continue;
            used[i] = 1; perm.push_back(nums[i]);
            bt(nums, perm, used, perms, n);
            used[i] = 0; perm.pop_back();
        }
    }
};
