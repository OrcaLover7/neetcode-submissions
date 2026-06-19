class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = (int)s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n-1; i >= 0; i--) for(int j = i; j < n; j++) if(s[i] == s[j] and (j-i <= 2 or dp[i+1][j-1])) dp[i][j] = 1;

        vector<string> part;
        vector<vector<string>> parts;

        bt(s, 0, part, parts, dp, n);

        return parts;
            
    }

    void bt(string& s, int i, vector<string>& part, vector<vector<string>>& parts, vector<vector<int>>& dp, int n){
        if(i == n){
            parts.push_back(part);
            return;
        }

        for(int j = i; j < n; j++){
            string sub_str = s.substr(i, j-i+1);
            if(dp[i][j]){
                part.push_back(sub_str);
                bt(s, j+1, part, parts, dp, n);
                part.pop_back();
            }
        }
    }
};
