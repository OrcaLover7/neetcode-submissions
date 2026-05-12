class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for(int i : st){
            if(!st.count(i-1)){
                int start = i;
                int count = 1;
                while(st.count(start+1)){
                    start++;
                    count++;
                }
                ans = max(count, ans);
            }
        }

        return ans;
    }
};
