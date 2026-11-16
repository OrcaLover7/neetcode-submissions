class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0;
        string ans_string = "";
        int n = (int)s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(((j-i <= 2) or dp[i+1][j-1]) and s[i] == s[j]){
                    dp[i][j] = true;
                    int l = j-i+1;
                    if(l > ans){
                        ans = l;
                        ans_string = s.substr(i, ans);
                    }
                }
            }
        }


        return ans_string;
    }
};
