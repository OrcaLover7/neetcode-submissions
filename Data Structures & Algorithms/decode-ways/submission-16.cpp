class Solution {
public:
    int numDecodings(string s) {
        //dp[i] = number of ways of counting from 0 to index i
        //dp[i] = number of ways of counting from 0 to i-1 + number of ways of counting from 0 to i-2. dp[i] = dp[i-1] + dp[i-2]
        // of course depends on how i-1 and i-2 look
        //base cases dp[0] = 0 if s[i] = '0', else dp[0] = 1; dp[1] = 1 if susbtr(0, 2) >= 10 and <= 26, else 0
        if(s[0] == '0') return 0;
        int n = (int)s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            string s1 = s.substr(i-1, 1);
            string s2 = s.substr(i-2, 2);

            dp[i] = ((s1 > "0") ? dp[i-1] : 0) + ((s2 >= "10" and s2 <= "26") ? dp[i-2] : 0);
        }

        return dp[n];
    }
};
