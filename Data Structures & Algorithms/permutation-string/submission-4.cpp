class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        array<int, 26> s1_freq = {};

        for(char c : s1) s1_freq[c-'a']++;

        array<int, 26> window_freq = {};

        int l = 0, r = 0;

        while(r < s2.size()){
            window_freq[s2[r]-'a']++;

            if(r-l+1 > s1.size()){
                window_freq[s2[l]-'a']--;
                l++;
            }
            if(window_freq == s1_freq) return true;
            r++;
        }

        return false;
    }
};
