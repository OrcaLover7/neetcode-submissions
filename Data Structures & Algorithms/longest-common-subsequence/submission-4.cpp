class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = (int)text1.size();
        int n = (int)text2.size();
        vector<vector<int>> dp(m, (vector<int>(n, -1)));

        return bt(text1, text2, 0, 0, dp);
    }

    int bt(string& t1, string& t2, int i, int j, vector<vector<int>>& dp){
        if(i == (int)t1.size() || j == (int)t2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(t1[i] == t2[j]) return dp[i][j] = 1 + bt(t1, t2, i+1, j+1, dp);

        return dp[i][j] = max(bt(t1, t2, i+1, j, dp), bt(t1, t2, i, j+1, dp));
    }

};
