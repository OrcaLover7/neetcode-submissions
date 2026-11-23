class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = (int)s1.size(), n2 = (int)s2.size(), n3 = (int)s3.size();

        if(n1 + n2 != n3) return false;

        vector<bool> dp(n2+1, false);

        for(int i2 = 0; i2 < n2; i2++) dp[i2] = s2.substr(i2, n2-i2) == s3.substr(n1 + i2, n3 - (n1 + i2));
        dp[n2] = true;


        for(int i1 = n1-1; i1 >= 0; i1--){
            dp[n2] = (s1[i1] == s3[i1 + n2] and dp[n2]);
            int curr_right = dp[n2];

            for(int i2 = n2-1; i2 >= 0; i2--){
                int i3 = i1 + i2;

                bool can_down = (s1[i1] == s3[i3] and dp[i2]);
                bool can_right = (s2[i2] == s3[i3] and curr_right);

                bool curr = can_down or can_right;

                dp[i2] = curr;
                curr_right = curr;
            }
        }

        return dp[0];

        
    }
};
