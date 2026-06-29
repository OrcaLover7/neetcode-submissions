class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int start_idx = 0, ans_len = 1;

        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] and (j-i <= 2 or dp[i+1][j-1])){
                    dp[i][j] = 1;
                    int len = j-i+1;
                    if(len > ans_len){
                        ans_len = len;
                        start_idx = i;
                    }
                }
            }
        }

        return s.substr(start_idx, ans_len);

    }
};
