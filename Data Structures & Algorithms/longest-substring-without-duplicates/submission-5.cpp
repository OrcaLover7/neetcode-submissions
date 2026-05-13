class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> last_seen;

        int l = 0, r = 0;

        int ans = 0;

        while(r < s.size()){
            char curr = s[r];

            if(last_seen.count(curr)){
                l = max(l, last_seen[curr]+1);
            }

            ans = max(ans, r-l+1);
            last_seen[curr] = r;
            r++;
        }

        return ans;
    }
};