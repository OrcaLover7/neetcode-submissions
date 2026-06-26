class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = (int)s.size();
        vector<int> dp(n, -1);
        
        return can_break(s, 0, dict, dp, n);
    }

    bool can_break(string& s, int start, unordered_set<string>& dict, vector<int>& dp, int n){
        if(start == n) return true;
        if(dp[start] != -1) return dp[start];

        for(int end = start; end < n; end++){
            string sub = s.substr(start, end-start+1);
            if(dict.count(sub) and can_break(s, end+1, dict, dp, n)) return dp[start] = 1;
        }

        return dp[start] = 0;
    }
};
