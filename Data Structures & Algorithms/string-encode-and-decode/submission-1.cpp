class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";

        for(auto& s : strs) ans += to_string((int)s.size()) + '#' + s;

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        for(int i = 0; i < (int)s.size(); ){
            int del_index = s.find('#', i);
            int sz = stoi(s.substr(i, del_index-i));

            int j = del_index + 1;
            int k = sz;
            string curr = "";

            while(k--) curr.push_back(s[j++]);

            ans.push_back(curr);

            i = del_index + sz + 1;
        }

        return ans;
    }
};
