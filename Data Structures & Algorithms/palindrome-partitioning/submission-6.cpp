class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = (int)s.size();

        vector<string> partition;
        vector<vector<string>> ans;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n-1; i >= 0; i--) for(int j = i; j < n; j++) if(s[i] == s[j] and (j-i <= 2 or dp[i+1][j-1])) dp[i][j] = 1;

        bt(s, 0, partition, ans, dp, n);

        return ans;
    }

    void bt(string& s, int index, vector<string>& partition, vector<vector<string>>& ans, vector<vector<int>>& dp, int n){
        if(index == n){
            ans.push_back(partition);
            return;
        }

        for(int j = index; j < n; j++){
            if(dp[index][j]){
                partition.push_back(s.substr(index, j-index+1));
                bt(s, j+1, partition, ans, dp, n);
                partition.pop_back();
            }
        }
    }
};
