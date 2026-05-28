class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;

        int n = (int)s.size();
        if(n == 1) return 1;

        unordered_set<string> st;
        for(int i = 1; i <= 26; i++) st.insert(to_string(i));

        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            string single = "";
            string doub = "";

            single += s[i-1];
            doub += s[i-2];
            doub += s[i-1];

            cout << single << "  " << doub << endl;

            auto p1 = st.count(single);
            auto p2 = st.count(doub);

            if(p1 && p2) dp[i] = dp[i-1] + dp[i-2];
            else if(p1 && !p2) dp[i] = dp[i-1];
            else if(!p1 && p2) dp[i] = dp[i-2];
            else dp[i] = 0;
        }

        return dp[n];
    }
};
