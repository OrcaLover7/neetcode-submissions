class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int l = 0, r = 0, ans = 0, max_freq = 0;

        unordered_map<char, int> freq;

        while(r < (int)s.size()){
            char curr = s[r];
            freq[curr]++;
            
            max_freq = max(max_freq, freq[curr]);

            int len = r-l+1;
            int rest = len - max_freq;

            if(rest > k){
                freq[s[l]]--;
                l++;
            }

            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};
