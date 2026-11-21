class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = (int)word1.size(), n2 = (int)word2.size();

        vector<int> next(n2+1, INT_MAX), curr(n2+1, INT_MAX);
        
        for(int j = 0; j <= n2; j++) next[j] = n2-j;

        for(int i = n1-1; i >= 0; i--)
        {
            curr[n2] = n1-i;
            for(int j = n2-1; j >= 0; j--){
                if(word1[i] == word2[j]) curr[j] = next[j+1];
                else curr[j] = 1 + min({next[j+1], curr[j+1], next[j]});
            }

            next = curr;
        }
        
        return next[0];
    }

};
