class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string ssf = "";
        bt(n, 0, ssf);

        return ans;
    }

    void bt(int n, int left_count, string& ssf){
        if(ssf.size() == 2*n){
            ans.push_back(ssf);
            return;
        }

        int right_count = ssf.size()-left_count;

        if(left_count < n){
            ssf.push_back('(');
            bt(n, left_count+1, ssf);
            ssf.pop_back();
        }

        if(right_count < left_count){
            ssf.push_back(')');
            bt(n, left_count, ssf);
            ssf.pop_back();
        }
    }
};