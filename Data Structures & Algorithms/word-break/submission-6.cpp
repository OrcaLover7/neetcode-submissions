class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = (int)s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(n+1, 0);

        dp[n] = 1;

        for(int i = n-1; i >= 0; i--) for(int j = i; j < n; j++) if(dict.count(s.substr(i, j-i+1)) and dp[j+1]) dp[i] = 1;
        
        return dp[0];

    }
};
