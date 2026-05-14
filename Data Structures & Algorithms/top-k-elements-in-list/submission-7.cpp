class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq_map;
        int n = (int)nums.size();

        for(int i : nums) freq_map[i]++;

        vector<vector<int>> buckets(n + 1);

        for(auto& [key, freq] : freq_map) buckets[freq].push_back(key);

        vector<int> ans;

        for(int i = n; i >= 0; i--){

            for(int key : buckets[i]){
                ans.push_back(key);
                if(ans.size() == k) return ans;
            }
        }

        return ans;
    }
};
