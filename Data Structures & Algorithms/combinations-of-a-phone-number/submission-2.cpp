class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(!(int)digits.size()) return {};
        unordered_map<char, string> digit_char;
        digit_char['2'] = "abc";
        digit_char['3'] = "def";
        digit_char['4'] = "ghi";
        digit_char['5'] = "jkl";
        digit_char['6'] = "mno";
        digit_char['7'] = "pqrs";
        digit_char['8'] = "tuv";
        digit_char['9'] = "wxyz";

        string ssf;
        vector<string> ans;

        bt(digits, ssf, ans, digit_char, 0);

        return ans;
    }

    void bt(string& digits, string& ssf, vector<string>& ans, unordered_map<char, string>& digit_char, int index){
        if(index == (int)digits.size()){
            ans.push_back(ssf);
            return;
        }

        for(char c : digit_char[digits[index]]){
            ssf.push_back(c);
            bt(digits, ssf, ans, digit_char, index+1);
            ssf.pop_back();
        }
    }
};
