class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = (int)s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(n, -1);

        return can_break(s, 0, dict, dp);
    }

    bool can_break(const string& s, int start, const unordered_set<string>& dict, vector<int>& dp){
        if(start >= (int)s.size()) return true;
        if(dp[start] != -1) return dp[start];
     
        for(int end = start; end < (int)s.size(); end++) if(dict.count(s.substr(start, end-start+1)) and can_break(s, end+1, dict, dp)) return dp[start] = 1;

        return dp[start] = 0;

    }
};
