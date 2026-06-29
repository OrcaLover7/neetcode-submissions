class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        int start_idx = 0, ans_len = 1;

        for(int i = 0; i < n; i++){
            //odd case
            int l = i, r = i;

            while(l >= 0 and r < n and s[l] == s[r]){
                int len = r-l+1;
                if(len > ans_len){
                    ans_len = len;
                    start_idx = l;
                }
                l--;
                r++;
            }

            l = i, r = i+1;

            while(l >= 0 and r < n and s[l] == s[r]){
                int len = r-l+1;
                if(len > ans_len){
                    ans_len = len;
                    start_idx = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(start_idx, ans_len);
    }
};
