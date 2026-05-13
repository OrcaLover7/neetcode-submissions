class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = (int)s.size();

        int l = 0, r = 0;
        int max_freq = 0;
        unordered_map<char, int> freq;

        while(r < n){
            char curr = s[r];
            freq[curr]++;

            max_freq = max(max_freq, freq[curr]);

            if((r-l+1 - max_freq) > k){
                freq[s[l]]--;
                l++;
            }

            r++;
        }

        return r-l;
    }
};
