class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        array<int, 26> s1_freq = {};

        for(char c : s1) s1_freq[c-'a']++;

        array<int, 26> window_freq = {};

        int l = 0, r = 0, matches = 0;

        for(int i = 0; i < 26; i++){
            if(window_freq[i] == s1_freq[i]) matches++;
        }

        if(matches == 26) return true;
        
        while(r < s2.size()){
            char c = s2[r];
            int _c = c-'a';
            window_freq[_c]++;

            if(window_freq[_c] == s1_freq[_c]) matches++;

            int window = r-l+1;

            if(window > s1.size()){
                char z = s2[l];
                int _z = z-'a';
                if(window_freq[_z] == s1_freq[_z]) matches--;
                window_freq[_z]--;
                l++;
            }
            if(matches == 26) return true;
            r++;
        }

        return false;
    }
};
