class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = (int)nums.size();

        int l = 0, r = 0, ls = -1, mx = INT_MIN;

        while(r < n){
            if(nums[r] > mx){
                mx = nums[r];
                ls = r;
            }

            int ws = r - l + 1;

            if(ws == k){
                ans.push_back(mx);
                if(ls == l){
                    int tmp = INT_MIN;
                    for(int i = l + 1; i <= r; i++){
                        if(nums[i] > tmp){
                            tmp = nums[i];
                            ls = i;
                        }
                    }
                    mx = tmp;
                }
                l++;
            }
            r++;
        }

        return ans;
    }
};
