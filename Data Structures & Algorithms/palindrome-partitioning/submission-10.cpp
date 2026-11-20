class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = (int)s.size();

        vector<vector<string>> ans;
        vector<string> path;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        //dp[i+1][j-1] = 1 if s[i] == s[j] and (dp[i+1][j-1] == 1 or j - i <= 2)

        for(int i = n-1; i >= 0; i--)
            for(int j = i; j < n; j++)
                if(s[i] == s[j] and (j - i <= 2 or dp[i+1][j-1])) dp[i][j] = true;
            
        bt(0, n, s, path, ans, dp);

        return ans;
    }

    void bt(int i, int n, string& s, vector<string>& path, vector<vector<string>>& ans, vector<vector<bool>>& dp){
        if(i == n) {
            ans.push_back(path);
            return;
        };

        for(int end = i; end < n; end++){
            if(dp[i][end]){
                path.push_back(s.substr(i, end-i+1));
                bt(end+1, n, s, path, ans, dp);
                path.pop_back();
            }
        }
    }
};


