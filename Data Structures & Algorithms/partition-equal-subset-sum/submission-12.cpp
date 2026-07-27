class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2) return false;
        int target = sum/2;
        vector<bool> v(n, false);

        return bt(nums, target, v, n);

    }

    bool bt(vector<int>& nums, int target, vector<bool>& v, int n){
        if(target == 0) return true;
        if(target < 0) return false;

        for(int i = 0; i < n; i++){
            if(!v[i]){
                v[i] = true;
                if(bt(nums, target - nums[i], v, n)) return true;;
                v[i] = false;
            }
        }

        return false;
    }
};
