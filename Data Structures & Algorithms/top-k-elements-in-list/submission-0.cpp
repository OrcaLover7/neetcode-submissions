class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int i : nums) freq[i]++;

        vector<pair<int, int>> v;

        for(auto& [key, value] : freq){
            v.push_back({value, key});
        }

        sort(v.begin(), v.end(), greater<>());

        vector<int> ans;

        for(int i =0; i < k; i++){
            ans.push_back(v[i].second);
        }

        return ans;
    }
};
