class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        if(n1 < n2) return "";

        int missing = n2;
        vector<int> need(128, 0);
        for(char c : t) need[c]++;

        int l = 0, r = 0, best_start = 0, best_len = INT_MAX;

        while(r < n1){
            if(need[s[r]] > 0) missing--;
            need[s[r]]--;

            while(missing == 0){
                int curr_w = r - l + 1;
                if(best_len > curr_w){
                    best_start = l;
                    best_len = curr_w;
                }

                need[s[l]]++;
                if(need[s[l]] > 0) missing++;
                l++;
            }
            r++;
        }

        return best_len == INT_MAX ? "" : s.substr(best_start, best_len);
    }
};
