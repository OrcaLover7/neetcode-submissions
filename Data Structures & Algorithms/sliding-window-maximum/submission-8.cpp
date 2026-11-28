class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<int> ans;
        priority_queue<pair<int, int>> max_heap;
        int l = 0, r = 0;

        while(r < n){
            max_heap.push({nums[r], r});
            
            if(r - l + 1 == k){
                while(max_heap.top().second < l) max_heap.pop();
                ans.push_back(max_heap.top().first);
                l++;
            }
            r++;
        }

        return ans;
    }
};
