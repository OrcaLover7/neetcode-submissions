class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = (int)nums.size();

        for(int i = 1; i <= n; i++){
            bool found = false;
            for(int a : nums){
                if(a == i){
                    if(found) return i;
                    found = true;
                }
            }
        }

        return -1;
    }
};
