class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = (int)s.size();
        vector<bool> dp(n+1, false);

        dp[n] = true;

        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(dp[j+1] and dict.count(s.substr(i, j-i+1))) {
                    dp[i] = true; 
                    break; 
                }
            }
        }

        return dp[0];
        
    }
};
