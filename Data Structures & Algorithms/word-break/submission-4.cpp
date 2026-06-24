class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = (int)s.size();
        unordered_set<string> dict;
        vector<int> dp(n+1, -1);
        
        for(auto& word : wordDict) dict.insert(word);

        for(int end = 0; end < n; end++){
            auto sub = s.substr(0, end+1);
            if(dict.count(sub)) if(find_word(s, end+1, dict, dp)) return true;
        }

        return false;
    }

    bool find_word(string& s, int start, unordered_set<string>& dict, vector<int>& dp){
        if(dp[start] != -1) return dp[start];
        if(start >= (int)s.size()) return true;
        
        for(int end = start; end < (int)s.size(); end++){
            auto sub = s.substr(start, end-start+1);
            if(dict.count(sub)){ 
                if(find_word(s, end+1, dict, dp)){
                    dp[start] = 1;
                    return true;
                }
            }
        }

        dp[start] = 0;
        return false;
    }
};
