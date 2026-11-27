class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = (int)nums.size();

        priority_queue<pair<int, int>> max_heap;
        int l = 0, r = 0;

        while(r < n){
            max_heap.push({nums[r], r});

            int ws = r - l + 1;

            if(ws == k){
                while(max_heap.top().second < l){
                    max_heap.pop();
                }
                ans.push_back(max_heap.top().first);
                l++;
            }
            r++;
        }

        return ans;
    }
};
