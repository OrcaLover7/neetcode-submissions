class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        // ans.push_back({});

        for(int i : nums){
            int n = ans.size();
            for(int j = 0; j < n; j++){
                vector<int> scp = ans[j];
                scp.push_back(i);
                ans.push_back(scp);
            }
        }

        return ans;
    }
};
