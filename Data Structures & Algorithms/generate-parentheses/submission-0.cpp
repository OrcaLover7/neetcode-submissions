class Solution {
public:
    vector<string> ans;

    bool isValid(string s){
        stack<char> st;

        for(char c : s){
            if(c == '(')
                st.push(c);
            else{
                if(st.empty()) return false;
                st.pop();
            }
        }

        return st.empty();
    }
    vector<string> generateParenthesis(int n) {
        string ssf = "";
        bt(n, ssf);
        return ans;
    }

    void bt(int n, string ssf){
        if(ssf.size() == 2*n){
            if(isValid(ssf)){
                ans.push_back(ssf);
            }

            return;
        }


        ssf.push_back('(');
        bt(n, ssf);
        ssf.pop_back();

        ssf.push_back(')');
        bt(n, ssf);
        ssf.pop_back();
    }
};
