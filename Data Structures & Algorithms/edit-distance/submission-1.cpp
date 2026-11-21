class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = (int)word1.size(), n2 = (int)word2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return bt(0, 0, word1, word2, n1, n2, dp);
    }

    int bt(int i, int j, string& word1, string& word2, int n1, int n2, vector<vector<int>>& dp){
        if(i == n1) return n2 - j;
        if(j == n2) return n1 - i;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) return dp[i][j] = bt(i+1, j+1, word1, word2, n1, n2, dp);

        int add = 0, replace = 0, remove = 0;

        //add
        add = bt(i, j+1, word1, word2, n1, n2, dp);
        //replace
        replace = bt(i+1, j+1, word1, word2, n1, n2, dp);
        //remove
        remove = bt(i+1, j, word1, word2, n1, n2, dp);

        return dp[i][j] = 1 + min({add, replace, remove});
    }
};
