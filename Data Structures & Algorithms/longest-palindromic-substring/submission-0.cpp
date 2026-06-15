class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));

        int res_index = 0, res_len = 0;

        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] and (j-i <= 2 or dp[i+1][j-1] == 1)){
                    dp[i][j] = 1;
                    int curr_len = j - i +1;
                    if(curr_len > res_len){
                        res_len = curr_len;
                        res_index = i;
                    }
                }
            }
        }

        return s.substr(res_index, res_len);
    }
};
