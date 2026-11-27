class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = (int)nums.size();

        multiset<int> ms;
        int l = 0, r = 0;

        while(r < n){
           ms.insert(nums[r]);

            int ws = r - l + 1;

            if(ws == k){
                ans.push_back(*ms.rbegin());
                ms.erase(ms.find(nums[l]));
                l++;
            }
            r++;
        }

        return ans;
    }
};
