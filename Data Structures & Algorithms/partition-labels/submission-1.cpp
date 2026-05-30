class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last_seen;
        int n = (int)s.size();

        for(int i = 0; i < n; i++) last_seen[s[i]] = i;

        vector<int> ans;

        int i = 0;

        while(i < n){
            int new_end = last_seen[s[i]];
            for(int j = i; j < n && j <= new_end; j++) new_end = max(new_end, last_seen[s[j]]);
            ans.push_back(new_end - i + 1);
            i = new_end + 1;
        }

        return ans;
    }
};
