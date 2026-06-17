class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();

        int idx = 0, len = 0;


        for(int i = 0; i < n; i++){
            int l = i, r = i;

            while(l >= 0 and r < n and s[l] == s[r]){
                if(r-l+1 > len){
                    len = r-l+1;
                    idx = l;
                }
                l--;
                r++;
            }

            l = i, r = i+1;

            while(l >= 0 and r < n and s[l] == s[r]){
                if(r-l+1 > len){
                    len = r-l+1;
                    idx = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(idx, len);
    }
};
