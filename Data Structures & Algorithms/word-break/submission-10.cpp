class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = (int)s.size();

        vector<int> dp(n+1, 0);

        dp[0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = i-1; j >= 0; j--){
                if(dp[j] and  dict.count(s.substr(j, i-j))){
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[n];
    }
};
