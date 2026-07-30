class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = (int)s.size();
        vector<string> part;
        vector<vector<string>> ans;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i = n-1; i >= 0; i--) for(int j = i; j < n; j++) if(s[i] == s[j] and (j-i <= 2 or dp[i+1][j-1])) dp[i][j] = true;

        bt(s, part, ans, 0, n, dp);
            
        return ans;
    }

    void bt(string s, vector<string>& part, vector<vector<string>>& ans, int index, int n, vector<vector<bool>>& dp){
        if(index == n){
            ans.push_back(part);
            return;
        }

        for(int j = index; j < n; j++){
            if(dp[index][j]){
                part.push_back(s.substr(index, j - index + 1));
                bt(s, part, ans, j+1, n, dp);
                part.pop_back();
            }
        }
    }
};
