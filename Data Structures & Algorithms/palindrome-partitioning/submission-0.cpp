class Solution {
public:

    bool is_palindrome(string& s){
        int l = 0, r = (int)s.size()-1;

        while(l < r){
            if(s[l] == s[r]){
                l++;
                r--;
            }
            else return false;
        }

        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<string> st;
        vector<vector<string>> ans;

        bt(s, st, ans, 0);

        return ans;
    }

    void bt(string& s, vector<string>& st, vector<vector<string>>& ans, int i){
        if(i == (int)s.size()){
            ans.push_back(st);
            return;
        }

        for(int j = i; j < (int)s.size(); j++){
            string sub_str = s.substr(i, j-i+1);
            if(is_palindrome(sub_str)){
                st.push_back(sub_str);
                bt(s, st, ans, j+1);
                st.pop_back();
            }
        }
    }
};
