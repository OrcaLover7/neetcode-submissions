class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string ssf = "";
        bt(n, ssf, 0);
        return ans;
    }

    void bt(int n, string& ssf, int open_count){
        if(ssf.size() == 2*n){
            ans.push_back(ssf);
            return;
        }

        if(open_count < n)
        {
            ssf.push_back('(');
            bt(n, ssf, open_count+1);
            ssf.pop_back();
        }

        if(open_count > (ssf.size()-open_count))
        {
            ssf.push_back(')');
            bt(n, ssf, open_count);
            ssf.pop_back();
        }
    }
};
