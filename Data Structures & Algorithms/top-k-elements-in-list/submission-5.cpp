class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;

        for(int& i : nums) freq_map[i]++;

        vector<vector<int>> buckets(nums.size()+1);

        for(auto& [key, freq] : freq_map) buckets[freq].push_back(key);
        vector<int> ans;

        for(int i = int(nums.size()); i >= 0; i--){
            for(int key : buckets[i]){
                ans.push_back(key);
                if(ans.size() == k)
                    return ans;
            }
        }
        return ans;
        
    }
};
