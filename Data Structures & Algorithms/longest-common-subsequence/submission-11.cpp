class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = (int)text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int> (n , -1));

        return bt(text1, text2, 0, 0, m, n, dp);
    }

    int bt(string& s1, string& s2, int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i == m or j == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return dp[i][j] = 1 + bt(s1, s2, i+1, j+1, m, n, dp);
        else return dp[i][j] = max(bt(s1, s2, i+1, j, m, n, dp), bt(s1, s2, i, j+1, m, n, dp));
    }
};
