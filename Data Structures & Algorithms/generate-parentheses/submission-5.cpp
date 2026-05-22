class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string ssf = "";
        vector<string> ans;
        bt(n, 0, ssf, ans);

        return ans;
    }

    void bt(int n, int open, string &ssf, vector<string>& ans){
        if((int)ssf.size() == n*2){
            ans.push_back(ssf);
            return;
        }

        int close = ssf.size() - open;

        if(open < n){
            ssf.push_back('(');
            bt(n, open + 1, ssf, ans);
            ssf.pop_back();
        }

        if(close < open){
            ssf.push_back(')');
            bt(n, open, ssf, ans);
            ssf.pop_back();
        }
    }
};
