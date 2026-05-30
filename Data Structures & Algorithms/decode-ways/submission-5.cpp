class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;

        int n = (int)s.size();
        if(n == 1) return 1;

        vector<int> dp(n+1, 0);
        unordered_set<string> st;

        for(int i = 1; i <= 26; i++) st.insert(to_string(i));

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            string sin = "";
            string doub = "";

            sin += s[i-1];
            doub = doub + s[i-2] + s[i-1];

            bool b1 = st.count(sin);
            bool b2 = st.count(doub);

            if(b1 && b2) dp[i] = dp[i-1] + dp[i-2];
            else if(b1 && !b2) dp[i] = dp[i-1];
            else if(!b1 && b2 ) dp[i] = dp[i-2];
            else dp[i] = 0;
        }

        return dp[n];
    }
};
