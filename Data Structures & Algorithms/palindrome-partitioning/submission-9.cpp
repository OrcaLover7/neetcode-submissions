class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = (int)s.size();

        vector<vector<string>> ans;
        vector<string> path;
        bt(0, n, s, path, ans);

        return ans;
    }

    void bt(int i, int n, string& s, vector<string>& path, vector<vector<string>>& ans){
        if(i == n) {
            ans.push_back(path);
            return;
        };

        for(int end = i; end < n; end++){
            if(isPalindrome(s, i, end)){
                path.push_back(s.substr(i, end-i+1));
                bt(end+1, n, s, path, ans);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++, r--;
        }

        return true;
    }
};


