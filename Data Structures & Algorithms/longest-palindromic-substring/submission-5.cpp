class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();

        int len = 0, start = 0;

        for(int i = 0; i < n; i++){
            //odd case
            int l = i, r = i;

            while(l >= 0 and r < n and s[l] == s[r]){
                int cur_len = r-l+1;
                if(cur_len > len){
                    len = cur_len;
                    start = l;
                }
                l--;
                r++;
            }

            l = i, r = i+1;

            while(l >= 0 and r < n and s[l] == s[r]){
                int cur_len = r-l+1;
                if(cur_len > len){
                    len = cur_len;
                    start = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(start, len);
    }
};
