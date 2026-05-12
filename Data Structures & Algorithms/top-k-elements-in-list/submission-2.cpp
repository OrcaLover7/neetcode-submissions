class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;

        for(int& i : nums) freq_map[i]++;

        priority_queue<pair<int, int>> maxHeap;

        for(auto& [key, freq] : freq_map) maxHeap.push({freq, key});

        vector<int> ans;

        while(k--){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;
    }
};
