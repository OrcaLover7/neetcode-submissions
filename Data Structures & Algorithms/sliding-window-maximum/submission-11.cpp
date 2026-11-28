class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<int> ans;
        deque<int> dq;
        int l = 0, r = 0;

        while(r < n){
            while(!dq.empty() and nums[dq.back()] <= nums[r])   dq.pop_back();
            dq.push_back(r);
            
            if(dq.front() < l)  dq.pop_front();

            if(r-l+1 == k){
                ans.push_back(nums[dq.front()]);
                l++;
            }

            r++;
        }


        return ans;
    }
};
