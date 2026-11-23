class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = (int)s1.size(), n2 = (int)s2.size(), n3 = (int)s3.size();

        if(n1 + n2 != n3) return false;

        vector<vector<int>> dp(n1+1, vector<int>(n1+1, -1));

        return bt(0, 0, 0, s1, s2, s3, n1, n2, n3, dp);
    }

    bool bt(int i1, int i2, int i3, string& s1, string& s2, string& s3, int n1, int n2, int n3, vector<vector<int>>& dp){
        if(i1 == n1) return dp[i1][i2] = s2.substr(i2, n2-i2) == s3.substr(i3, n3-i3);
        if(i2 == n2) return dp[i1][i2] = s1.substr(i1, n1-i1) == s3.substr(i3, n3-i3);

        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(s1[i1] == s3[i3] and bt(i1+1, i2, i3+1, s1, s2, s3, n1, n2, n3, dp)) return dp[i1][i2] = true;
        if(s2[i2] == s3[i3] and bt(i1, i2+1, i3+1, s1, s2, s3, n1, n2, n3, dp)) return dp[i1][i2] = true;

        return dp[i1][i2] = false;
    }
};
