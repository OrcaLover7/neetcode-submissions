class Solution {
public:
    //O(n^2) time and O(1) space
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = (int)nums.size();

        for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) if(nums[i] + nums[j] == target) return {i, j};
        
        return {};
        
    }
};
