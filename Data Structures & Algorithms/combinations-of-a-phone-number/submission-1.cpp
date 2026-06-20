class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(!digits.size()) return ans;
        unordered_map<char, vector<char>> digit_map;

        digit_map['2'] = {'a', 'b', 'c'};
        digit_map['3'] = {'d', 'e', 'f'};
        digit_map['4'] = {'g', 'h', 'i'};
        digit_map['5'] = {'j', 'k', 'l'};
        digit_map['6'] = {'m', 'n', 'o'};
        digit_map['7'] = {'p', 'q', 'r', 's'};
        digit_map['8'] = {'t', 'u', 'v'};
        digit_map['9'] = {'w', 'x', 'y', 'z'};

        string ssf = "";

        bt(digits, ssf, ans, 0, digit_map);

        return ans;
    }

    void bt(string& digits, string& ssf, vector<string>& ans, int index, unordered_map<char, vector<char>>& digit_map){
        if((int)ssf.size() == (int)digits.size()){
            ans.push_back(ssf);
            return;
        }

        for(auto& ch : digit_map[digits[index]]) {
            ssf.push_back(ch);
            bt(digits, ssf, ans, index+1, digit_map);
            ssf.pop_back();
        }
    }
};
