class Solution {
public:
    int countSubstrings(string s) {
        int n = (int)s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0;

        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] and (j-i <= 2 or dp[i+1][j-1])){
                    dp[i][j] = 1;
                    ans++;
                }
            }
        }

        return ans;
    }
};
