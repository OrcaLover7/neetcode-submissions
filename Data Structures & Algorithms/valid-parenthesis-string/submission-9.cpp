class Solution {
public:
    bool checkValidString(string s) {
        int n = (int)s.size(); 
        vector<bool> dp(n+2, false);
        dp[0] = true;

        for(int i = n-1; i >= 0; i--){
            vector<bool> dp_next(n+2, false);
            for(int k = 0; k <= n; k++){
                bool ok = false;

                if(s[i] == '(') ok = dp[k+1];
                else if(s[i] == ')') ok = k > 0 and dp[k-1];
                else ok = dp[k+1] or (k > 0 and dp[k-1]) or dp[k];
                dp_next[k] = ok;
            }

            dp = move(dp_next);
        }

        return dp[0];
    }
};
