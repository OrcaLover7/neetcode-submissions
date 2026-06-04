class Solution {
public:
    int jump(vector<int>& nums) {
        int n = (int)nums.size();

        int farthest = 0;
        int curr_end = 0;
        int jumps = 0;

        for(int i = 0; i < n-1; i++){
            farthest = max(farthest, i + nums[i]);
            if(curr_end == i){
                jumps++;
                curr_end = max(curr_end, farthest);
            }
        }

        return jumps;
    }
};
