class Solution {
public:
    //one way is to maybe binary search on the answer?
    int characterReplacement(string s, int k) {
        
        int l = 0, r = 0, ans = 0;
        int max_freq = 0;

        unordered_map<char, int> freq;

        while(r < s.size()){
            char c = s[r];
            freq[c]++;
            max_freq = max(max_freq, freq[c]);
            int len = r-l+1;
            int rest = len-max_freq;

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
