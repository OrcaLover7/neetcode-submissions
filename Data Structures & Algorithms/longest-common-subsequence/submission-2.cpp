class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = (int)text1.size();
        int n = (int)text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int ans = 0;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]){
                    for(int k1 = 0; k1 < i; k1++){
                        for(int k2 = 0; k2 < j; k2++){
                            dp[i][j] = max(dp[k1][k2] + 1, dp[i][j]);
                        }
                    }
                }
                ans = max(ans, dp[i][j]);
            }
            
        }

        return ans;
    }

};
