class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++)
        {
            auto& a = nums[i];
            int k = target - a;

            if(mp.count(k))
            {
                return {mp[k], i};
            }
            
            mp[a] = i;
        }

        return {};
    }
};
