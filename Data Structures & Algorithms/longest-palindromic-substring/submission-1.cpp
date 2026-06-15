class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();

        int res_index = 0, res_len = 0;

        for(int i = 0; i < n; i++){
            //odd
            int l = i, r = i;

            while(l >= 0 and r < n and s[l] == s[r]){
                if(r-l+1 > res_len){
                    res_len = r-l+1;
                    res_index = l;
                }
                l--;
                r++;
            }

            //even
            l = i;
            r = i+1;

            while(l >= 0 and r < n and s[l] == s[r]){
                if(r-l+1 > res_len){
                    res_index = l;
                    res_len = r-l+1;
                }
                l--;
                r++;
            }
        }
        return s.substr(res_index, res_len);
    }
};
