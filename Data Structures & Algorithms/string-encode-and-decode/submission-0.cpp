#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";

        for(string& s : strs){
            int n = int(s.size());
            ans += to_string(n) + '#' + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        for(int i = 0; i < (int)s.size();){
            int del_index = s.find('#', i);
            string sz = s.substr(i, del_index - i);
            int size = stoi(sz);

            int j = del_index+1;
            string curr;
            int k = size;
            while(k--) curr.push_back(s[j++]);
            ans.push_back(curr);

            i = del_index + size + 1;
        }

        return ans;
    }
};
