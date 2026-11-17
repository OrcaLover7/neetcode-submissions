class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return bt(0, s, dp);
    }

    int bt(int start, string& s, vector<int>& dp){
        if(start >= (int)s.size()) return 1;
        if(dp[start] != -1) return dp[start];
        if(s[start] == '0') return dp[start] = 0;

        int c1 = bt(start + 1, s, dp);
        int c2 = 0;

        if(start + 1 < s.size()){
            string s2 = s.substr(start, 2);
            if(s2 >= "10" and s2 <= "26") c2 = bt(start + 2, s, dp);
        }
        return dp[start] = c1 + c2;
    }
};
