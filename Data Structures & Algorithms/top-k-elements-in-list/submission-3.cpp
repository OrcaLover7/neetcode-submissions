class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;

        for(int& i : nums) freq_map[i]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(auto& [key, freq] : freq_map){
            if(minHeap.size() == k){
                if(minHeap.top().first < freq){
                    minHeap.pop();
                    minHeap.push({freq, key});
                }
            }
            else minHeap.push({freq,key});
        }

        vector<int> ans;

        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
        
    }
};
