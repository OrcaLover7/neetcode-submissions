class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();

        vector<int> prefix(n+1, 0);
        vector<int> suffix(n+1, 0);

        prefix[0] = 1;

        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1]*nums[i-1];
        }

        suffix[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            suffix[i] = suffix[i+1]*nums[i+1];
        }

        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++) ans[i] = prefix[i]*suffix[i];

        return ans;
    }
};
