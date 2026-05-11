class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = (int)s.size();
        
        if(!n) return 0;
        int l = 0, r = 0, ans = 1;
        unordered_map<char, int> mp;

        while(r < n){
            auto it = mp.find(s[r]);

            if(it != mp.end()){
                l = max(l, mp[s[r]] + 1);
            }

            ans = max(r-l+1, ans);
            mp[s[r]] = r;
            r++;
        }

        return ans;
    }
};
