class Solution {
public:
    int numDecodings(string s) {
        unordered_map<string, char> dict;
        char start = 'A';
        for(int i = 1; i <= 26; i++) dict[to_string(i)] = start++; 
        vector<int> dp(s.size(), -1);

        return bt(0, s, dict, dp);
    }

    int bt(int start, string s, unordered_map<string, char>& dict, vector<int>& dp){
        if(start >= (int)s.size()) return 1;
        if(dp[start] != -1) return dp[start];

        if(s[start] == '0') return dp[start] = 0;

        int c1 = bt(start + 1, s, dict, dp);
        int c2 = (start + 1 < (int)s.size() and dict.count(s.substr(start, 2))) ? bt(start + 2, s, dict, dp) : 0;

        return dp[start] = c1 + c2;
    }
};
