class Solution {
public:

    vector<vector<string>> partition(string s) {
        vector<string> st;
        vector<vector<string>> ans;
        int n = (int)s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n-1; i >= 0; i--) for(int j = i; j < n; j++)if(s[i] == s[j] and (j-i <= 2 or dp[i+1][j-1])) dp[i][j] = 1;

        bt(s, st, ans, 0, dp);

        return ans;
    }

    void bt(string& s, vector<string>& st, vector<vector<string>>& ans, int i, vector<vector<int>>& dp){
        if(i == (int)s.size()){
            ans.push_back(st);
            return;
        }

        for(int j = i; j < (int)s.size(); j++){
            string sub_str = s.substr(i, j-i+1);
            if(dp[i][j]){
                st.push_back(sub_str);
                bt(s, st, ans, j+1, dp);
                st.pop_back();
            }
        }
    }
};
