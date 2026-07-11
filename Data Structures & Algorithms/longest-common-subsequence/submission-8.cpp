class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        if(text1.size() < text2.length()) swap(text1, text2);

        int m = (int)text1.size();
        int n = (int)text2.size();

        vector<int> dp(n+1, 0);
        vector<int> prev(n+1, 0);

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]) dp[j] = prev[j-1] + 1;
                else dp[j] = max(dp[j-1], prev[j]);
            }

            swap(prev, dp);
        }

        return prev[n];
    }
};
