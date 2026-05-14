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

        while(r < s2.size()){
            int _c = s2[r]-'a';

            if(window_freq[_c] == s1_freq[_c])matches--;

            window_freq[_c]++;

            if(window_freq[_c] == s1_freq[_c]) matches++;

            if(r-l+1 > s1.size()){
                int _z = s2[l]-'a';
                if(window_freq[_z] == s1_freq[_z]) matches--;
                window_freq[_z]--;
                if(window_freq[_z] == s1_freq[_z]) matches++; 
                l++;
            }
            if(matches == 26) return true;
            r++;
        }

        return false;
    }
};
