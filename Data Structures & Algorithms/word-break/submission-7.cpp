class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = (int)s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(n+1, 0);

        dp[0] = 1;

        for(int i = 1; i <= n; i++) for(int j = 0; j < i; j++) if(dp[j] and dict.count(s.substr(j, i-j))) dp[i] = 1;
        
        return dp[n];

    }
};
