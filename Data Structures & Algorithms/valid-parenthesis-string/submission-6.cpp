class Solution {
public:
    bool checkValidString(string s) {
        int n = (int)s.size(); 
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return bt(0, 0, s, n, dp);
    }

    bool bt(int i, int open_count, string& s, int n, vector<vector<int>>& dp){
        if(open_count < 0) return false;

        if (i == n) {
            return open_count == 0;
        }
        if(dp[i][open_count] != -1) return dp[i][open_count];

        if(s[i] == '(') return dp[i][open_count] =  bt(i+1, open_count + 1, s, n, dp);
        else if(s[i] == ')') return dp[i][open_count] = bt(i+1, open_count - 1, s, n, dp);
        else return dp[i][open_count] = bt(i+1, open_count + 1, s, n, dp) or bt(i+1, open_count - 1, s, n, dp) or bt(i+1, open_count, s, n, dp);
        
    }

};
