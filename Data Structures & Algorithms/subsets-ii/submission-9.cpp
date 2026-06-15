class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans = {{}};

        int prev_size = 0;
        int start = 0;
        
        for(int i = 0; i < n; i++){
            start = (i >= 1 and nums[i] == nums[i-1]) ? prev_size : 0;
            prev_size = (int)ans.size();

            for(int j = start; j < prev_size; j++){
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }


        return ans;
    }
};
