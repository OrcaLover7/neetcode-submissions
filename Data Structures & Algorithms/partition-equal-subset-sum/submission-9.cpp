class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size();
        int sum = 0;
        for(int num : nums) sum += num;
        if(sum%2) return false;

        int target = sum/2;
        vector<int> v(n, 0);

        return bt(nums, 0, target, v, n);

    }

    bool bt(vector<int>& nums, int ssf, int target, vector<int>& v, int n){
        if(target == ssf){
            return true;
        }

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
