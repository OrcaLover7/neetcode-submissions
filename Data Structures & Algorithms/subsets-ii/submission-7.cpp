class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> ans = {{}};
        sort(nums.begin(), nums.end());

        int start = 0;
        int prevsize = 0;


        for(int i = 0; i < (int)nums.size(); i++){
            start = (i >= 1 and nums[i] == nums[i-1]) ? prevsize : 0;
            prevsize = (int)ans.size();

            for(int j = start; j < prevsize; j++){
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }

        return ans;
    }


};
