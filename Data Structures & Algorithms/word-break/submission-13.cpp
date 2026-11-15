class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set = unordered_set<string>(wordDict.begin(), wordDict.end());
        int n = (int)s.size();
        vector<int> dp(n+1, -1);

        return bt(0, s, word_set, dp);
    }

    bool bt(int start, string s, unordered_set<string>& word_set, vector<int>& dp){
        int n = (int)s.size();
        if(start == n) return true;
        if(dp[start] != -1) return dp[start];

        for(int l = 1; l <= n - start; l++){
            string curr = s.substr(start, l);
            if(word_set.count(curr) and bt(start+l, s, word_set, dp)) return dp[start] = true;
        }

        return dp[start] = false;
    }
};
