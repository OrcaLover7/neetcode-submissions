class Solution {
public:
    bool checkValidString(string s) {
        int n = (int)s.size(); 
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));

        dp[n][0] = true;

        for(int i = n-1; i >= 0; i--){
            for(int k = 0; k <= n; k++){
                bool ok = false;

                if(s[i] == '('){
                    if(k + 1 <= n) ok = dp[i+1][k+1];
                }
                else if(s[i] == ')'){
                    if(k > 0) ok = dp[i+1][k-1];
                }
                else{
                    bool as_open = (k + 1 <= n) and dp[i+1][k+1];
                    bool as_close = (k > 0) and dp[i+1][k-1];
                    bool as_space = dp[i+1][k];

                    ok = as_open or as_close or as_space;
                }

                dp[i][k] = ok;
            }
        }

        return dp[0][0];
    }
};
