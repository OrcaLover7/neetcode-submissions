class Solution {
public:
    //O(n^2) time and O(1) space - sorting does not work coz you need indices as the asnewr
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = (int)nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            int complement = target - nums[i];
            auto it = mp.find(complement);  //O(1) amortized
            if(it != mp.end()) return {it->second, i};
            mp[nums[i]] = i; //O(1) amortized
        }

        return {};
        
    }
};
