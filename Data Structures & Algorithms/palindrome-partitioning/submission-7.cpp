class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = (int)s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        //dp[i][j] = true if s[i..j] is a palindrome

        for(int i = n-1; i >= 0; i--) for(int j = i; j < n; j++) if(s[i] == s[j] and (j-i <= 2 or dp[i+1][j-1])) dp[i][j] = true;

        vector<string> part;
        vector<vector<string>> ans;

        bt(s, 0, part, ans, n, dp);
        
        return ans;
    }

    void bt(string s, int i, vector<string>& part, vector<vector<string>>& ans, int n, vector<vector<bool>>& dp){
        if(i == n){
            ans.push_back(part);
            return;
        }

        for(int j = i; j < n; j++){
            if(dp[i][j]){
                part.push_back(s.substr(i, j-i+1));
                bt(s, j+1, part, ans, n, dp);
                part.pop_back();
            }
        }
    }
};
