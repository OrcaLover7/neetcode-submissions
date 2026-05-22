class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string ssf = "";
        vector<string> ans;
        int open = 0;
        bt(n, open, ssf, ans);

        return ans;
    }

    void bt(int n, int& open, string &ssf, vector<string>& ans){
        if((int)ssf.size() == n*2){
            ans.push_back(ssf);
            return;
        }

        int close = ssf.size() - open;

        if(open < n){
            ssf.push_back('(');
            open++;
            bt(n, open, ssf, ans);
            open--;
            ssf.pop_back();
        }

        if(close < open){
            ssf.push_back(')');
            bt(n, open, ssf, ans);
            ssf.pop_back();
        }
    }
};
