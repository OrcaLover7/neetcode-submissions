class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = (int)word1.size(), n2 = (int)word2.size();
        vector<int> dp(n2+1, INT_MAX);

        for(int j = 0; j <= n2; j++) dp[j] = n2-j;

        for(int i = n1-1; i >= 0; i--){
            int next_diag = dp[n2];
            dp[n2] = n1-i;
            int curr_right = dp[n2];

            for(int j = n2-1; j >= 0; j--){
                int new_val;
                int old_down = dp[j];

                if(word1[i] == word2[j]) new_val = next_diag;
                else new_val = 1 + min({curr_right, next_diag, old_down});

                dp[j] = new_val;

                curr_right = new_val;
                next_diag = old_down;
            }
        
        }

        return dp[0];
    }

};
