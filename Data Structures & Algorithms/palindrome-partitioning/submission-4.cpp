class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = (int)s.size();
        vector<string> partition;
        vector<vector<string>> ans;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n-1; i >= 0; i--) for(int j = i; j < n; j++) if(s[i] == s[j] and (j-i <= 2 or dp[i+1][j-1])) dp[i][j] = 1;

        bt(s, partition, ans, dp, 0, n);

        return ans;
    }

    void bt(string& s, vector<string>& partition, vector<vector<string>>& ans, vector<vector<int>>& dp, int i, int n){
        if(i == n){
            ans.push_back(partition);
            return;
        }

        for(int j = i; j < n; j++){
            if(dp[i][j]){
                string sub_str = s.substr(i, j-i+1);
                partition.push_back(sub_str);
                bt(s, partition, ans, dp, j+1, n);
                partition.pop_back();
            }
        }
    }
};
