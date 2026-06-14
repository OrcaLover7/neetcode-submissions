class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0;
        int farthest = 0;
        int jumps = 0;

        for(int i = 0; i < (int)nums.size()-1; i++){
            farthest = max(farthest, i + nums[i]);
            if(i == end){
                jumps++;
                end = farthest;
            }
        }

        return jumps;
    }
};
