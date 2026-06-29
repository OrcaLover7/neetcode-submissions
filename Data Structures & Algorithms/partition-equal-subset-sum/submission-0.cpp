class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size();
        int total = 0;

        for(int i : nums) total += i;

        if(total%2) return false;
        vector<int> v(n, 0);

        return bt(nums, 0, total/2, v, n);
    }

    bool bt(vector<int>& nums, int ssf, int target, vector<int>& v, int n){
        if(ssf == target) return true;

        if(ssf > target) return false;

        for(int i = 0; i < n; i++){
            if(!v[i]){
                ssf += nums[i];
                v[i] = 1;
                if(bt(nums, ssf, target, v, n)) return true;
                v[i] = 0;
                ssf -= nums[i];
            }
        }

        return false;
    }
};
