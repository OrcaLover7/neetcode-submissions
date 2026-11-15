class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = (int)s.size();

        vector<bool> dp(n+1, false);
        dp[0] = true;
        //dp[i] = true if 0, i is findable, false otherwise
        //dp[0] = true -- why? empty string is always findable?

        for(int i = 1; i <= n; i++){
            for(int j = i-1; j >= 0; j--){
                if(dp[j] and dict.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
