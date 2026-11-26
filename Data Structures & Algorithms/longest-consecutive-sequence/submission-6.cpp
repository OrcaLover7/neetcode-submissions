class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> dict(nums.begin(), nums.end());
        int ans = 0;

        for(int num : dict){
            if(!dict.count(num-1)){
                int candidate = num;
                int curr_len = 1;
                // dict.erase(num);
                num++;
                while(dict.count(num)){
                    curr_len++;
                    // dict.erase(num);
                    num++;
                }
                ans = max(ans, curr_len);
            }
        }

        return ans;
    }
};
